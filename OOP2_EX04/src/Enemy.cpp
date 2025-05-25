#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
    :MovingObject(location, wantedSize, ObjectType::Enemy)
{
    m_direction = sf::Vector2f(1.f, 1.f); // איתחול כיוון למעלה
}


sf::FloatRect Enemy::getGlobalBounds() const
{
    return m_picture.getGlobalBounds(); // גם כאן יש תמונה
}

void Enemy::handleCollision(Object& object, GameInfo& gameInfo) {
    object.handleCollision(*this, gameInfo);  // -> Player::handleCollision(Enemy&)
}

void Enemy::handleCollision(Player& player, GameInfo& gameInfo) {
    if (this->getGlobalBounds().intersects(player.getGlobalBounds())) {
        gameInfo.setIsViolation(true);
    }
}



void Enemy::move(float& seconds, TileBoard& boardTiles, GameInfo& gameInfo)
{
    sf::Vector2f velocity = m_direction * seconds * MovementConsts::MOVE_PIXEL_ENEMY;
    sf::Vector2f newLocation = m_location + velocity;

    int row = static_cast<int>(newLocation.y / boardTiles.getSizeTile().y);
    int col = static_cast<int>(newLocation.x / boardTiles.getSizeTile().x);

    // בדיקה אם מחוץ ללוח או פוגע במסגרת או נכנס לשטח סגור
    if (!boardTiles.inArea(newLocation) ||
        boardTiles.isframeTileForMove(newLocation) ||
        boardTiles.getType(row, col) == ObjectType::Filled)
    {
        // שנה כיוון, נניח לפי סדר או רנדומלי (כמו שעשית קודם)
        // פה אפשר לשלב רנדומלי אם נתקע, אחרת סיבוב רגיל
        //changeDirection(); // ← רק אם כבר מימשת
        newDiractoin(boardTiles, newLocation);
        return; // לא זז
    }

    // כניסה לשובל - עבירה
    if (boardTiles.getType(row, col) == ObjectType::Trail) {
        gameInfo.setIsViolation(true);
    }

    // עדכון מיקום
    m_picture.move(velocity);
    m_location = newLocation;

    // אם צריך, בצע רקורסיה לכיבוש
    if (gameInfo.getNeedAreaCheck()) {
        floodFillArea(boardTiles, gameInfo, row, col);

        // עדכון אחרי הרקורסיה – ספירה מחדש
        int filled = countFilledTiles(boardTiles); // מספר אריחים שנכבשו בפועל
        int total = (boardTiles.getRows() - 2) * (boardTiles.getCols() - 2); // כל האריחים שאפשר לכבוש (ללא מסגרת)

        gameInfo.updateCapturedArea(filled, total); // עדכון שטח שנכבש באחרוזיפ
        gameInfo.addScoreForCaptured(filled); // עדכון נקודות 

        return;
    }
}


int Enemy::countFilledTiles(TileBoard& boardTiles) {
    int count = 0;
    for (int row = 0; row < boardTiles.getRows(); row++) {
        for (int col = 0; col < boardTiles.getCols(); col++) {
            Tile& tile = boardTiles.getTile(row, col);

            if (!tile.getIsVisited() && tile.getType() != ObjectType::Frame) {
                count++; // תא שלא ביקרו בו ואיננו מסגרת – נספר ככבוש
            }
        }
    }
    return count;
}



void Enemy::newDiractoin(const TileBoard& boardTiles, const sf::Vector2f& location)
{
    // חישוב אינדקס שורה ועמודה מהמיקום
    int row = static_cast<int>(location.y / GameConsts::sizeTile.y);
    int col = static_cast<int>(location.x / GameConsts::sizeTile.x);

    // בדיקת תנאי להחלפת כיוון
    bool hitObstacle = boardTiles.isframeTileForMove(location);
    bool filled = boardTiles.getType(row, col) == ObjectType::Filled;

    if (hitObstacle) {

        // שינוי כיוון בהתאם לכיוון הנוכחי
        if (m_direction == sf::Vector2f(1, 1))         // ↘
            m_direction = sf::Vector2f(1.f, -1.f);     // ↗
        else if (m_direction == sf::Vector2f(1, -1))   // ↗
            m_direction = sf::Vector2f(-1.f, -1.f);    // ↖
        else if (m_direction == sf::Vector2f(-1, -1))  // ↖
            m_direction = sf::Vector2f(-1.f, 1.f);     // ↙
        else if (m_dhhirection == sf::Vector2f(-1, 1))   // ↙
            m_direction = sf::Vector2f(1.f, 1.f);      // ↘
    }


    else if (filled) {

        if (m_direction == sf::Vector2f(1, -1))   // ↗
            m_direction = sf::Vector2f(1.f, 1.f);
    }
    else
        return;

}


void Enemy::floodFillArea(TileBoard& boardTiles, GameInfo& gameInfo, int row, int col)
{
    // תנאי יציאה: אינדקסים מחוץ לתחום
    if (row < 0 || col < 0 || row >= boardTiles.getRows() || col >= boardTiles.getCols())
        return;

    Tile& tile = boardTiles.getTile(row, col);

    // אם האריח כבר בוקרה או לא מסוג Empty – לא ממשיכים
    if (tile.getIsVisited() || tile.getType() != ObjectType::Empty)
        return;

    // סימון כביקור
    tile.setVisited(true);

    // קריאה רקורסיבית לארבעת הכיוונים
    floodFillArea(boardTiles, gameInfo, row - 1, col); // למעלה
    floodFillArea(boardTiles, gameInfo, row + 1, col); // למטה
    floodFillArea(boardTiles, gameInfo, row, col - 1); // שמאלה
    floodFillArea(boardTiles, gameInfo, row, col + 1); // ימינה
}




//void drop(int y, int x)// the function getting the enemy location
//{
//    //כאן זה הרקורסיה
//   // כל שומר בודק מה הטח שהוא יכול ליהות בו וכל מה שהו יכול ליהות בו הוא מסמן את המשבצת ב -1
//    if (grid[y][x] == 0) 
//        grid[y][x] = -1;
//
//    if (grid[y - 1][x] == 0) 
//        drop(y - 1, x);
//
//    if (grid[y + 1][x] == 0)
//        drop(y + 1, x);
//
//    if (grid[y][x - 1] == 0) 
//        drop(y, x - 1);
//
//    if (grid[y][x + 1] == 0)
//        drop(y, x + 1);
//}


//
//#include <SFML/Graphics.hpp>
//#include <time.h>
//using namespace sf;
//
//const int M = 25;
//const int N = 40;
//
//int grid[M][N] = { 0 };
//int ts = 18; //tile size
//
//struct Enemy
//{
//    int x, y, dx, dy;
//
//    Enemy()
//    {
//        x = y = 300;
//        dx = 4 - rand() % 8;
//        dy = 4 - rand() % 8;
//    }
//
//    void move()
//    {
//        x += dx; // תזוז בציר ה x
//       if (grid[y / ts][x / ts] == 1) //אם נגעת באיזור בטוח תלך ברוורס
//           { dx = -dx; x += dx; }
//       
//        y += dy;//תזוז בציר ה y
//        if (grid[y / ts][x / ts] == 1)//אם נגעת באיזור בטוח תלך ברוורס 
//        { dy = -dy; y += dy; }
//       
//    }
//};
//
//void drop(int y, int x)// the function getting the enemy location
//{
//    //כאן זה הרקורסיה
//   // כל שומר בודק מה הטח שהוא יכול ליהות בו וכל מה שהו יכול ליהות בו הוא מסמן את המשבצת ב -1
//    if (grid[y][x] == 0) 
//        grid[y][x] = -1;
//
//    if (grid[y - 1][x] == 0) 
//        drop(y - 1, x);
//
//    if (grid[y + 1][x] == 0)
//        drop(y + 1, x);
//
//    if (grid[y][x - 1] == 0) 
//        drop(y, x - 1);
//
//    if (grid[y][x + 1] == 0)
//        drop(y, x + 1);
//}
//
//int main()
//{
//    srand(time(0));
//
//    RenderWindow window(VideoMode(N * ts, M * ts), "Xonix Game!");
//    window.setFramerateLimit(60);
//
//    Texture t1, t2, t3;
//    t1.loadFromFile("tiles.png");
//    t2.loadFromFile("gameover.png");
//    t3.loadFromFile("enemy.png");
//
//    Sprite sTile(t1), sGameover(t2), sEnemy(t3);
//    sGameover.setPosition(100, 100);
//    sEnemy.setOrigin(20, 20);
//
//    int enemyCount = 4;
//    Enemy a[10];
//
//    bool Game = true;
//    int x = 0, y = 0, dx = 0, dy = 0;
//    float timer = 0, delay = 0.07;
//    Clock clock;
//
//    for (int i = 0; i < M; i++)
//        for (int j = 0; j < N; j++)
//            if (i == 0 || j == 0 || i == M - 1 || j == N - 1)  grid[i][j] = 1;// איתחול מסגרת
//
//    while (window.isOpen())
//    {
//        float time = clock.getElapsedTime().asSeconds();
//        clock.restart();
//        timer += time;
//
//        Event e;
//        while (window.pollEvent(e))
//        {
//            if (e.type == Event::Closed)
//                window.close();
//
//            if (e.type == Event::KeyPressed)
//                if (e.key.code == Keyboard::Escape)// analyze the bord
//                {
//                    for (int i = 1; i < M - 1; i++)
//                        for (int j = 1; j < N - 1; j++)
//                            grid[i][j] = 0;
//
//                    x = 10; y = 0;
//                    Game = true;
//                }
//        }
//
//        if (Keyboard::isKeyPressed(Keyboard::Left)) { dx = -1; dy = 0; };
//        if (Keyboard::isKeyPressed(Keyboard::Right)) { dx = 1; dy = 0; };
//        if (Keyboard::isKeyPressed(Keyboard::Up)) { dx = 0; dy = -1; };
//        if (Keyboard::isKeyPressed(Keyboard::Down)) { dx = 0; dy = 1; };
//
//        if (!Game) continue;
//
//        if (timer > delay)//to do it avrey 0.07 second
//        {
//            x += dx;//move x
//            y += dy;//move y
//
//            if (x < 0) x = 0; if (x > N - 1) x = N - 1;//לא לחרוג מגבולות הלוח
//            if (y < 0) y = 0; if (y > M - 1) y = M - 1;//לא לחרוג מגבולות הלוח
//
//            if (grid[y][x] == 2) 
//                Game =  false;//אם נגעת בקוביה שהיא עכשיו שובל נפסלת 
//            if (grid[y][x] == 0) 
//                grid[y][x] = 2;// אם אתה נכנסת לאיזור סיכון הפוך את המשבצת לשובל
//            timer = 0;
//        }
//
//        for (int i = 0; i < enemyCount; i++) a[i].move();// move all the gurd
//
//        if (grid[y][x] == 1)//if you in a save zone
//        {
//            dx = dy = 0;// move only if you praceing the bouton
//
//            for (int i = 0; i < enemyCount; i++)
//                drop(a[i].y / ts, a[i].x / ts);
//            //אני עובר על כל המטריצה ומעדכן איפה שכל שומר אמר שהוא יכול ליהות 
//            // אני הופך את זה לאיזור סיכון ואם הוא לא יכול ליהות אז אני הופך את זה לאיזור בטוח
////
//            for (int i = 0; i < M; i++)
//                for (int j = 0; j < N; j++)
//                    if (grid[i][j] == -1) grid[i][j] = 0;
//                    else grid[i][j] = 1;
//        }
//
//        for (int i = 0; i < enemyCount; i++)// אם האויב נגע בשובל נפסלת
//            if (grid[a[i].y / ts] [a[i].x / ts] == 2) Game = false;
//
//        /////////draw//////////
//        window.clear();
//
//        for (int i = 0; i < M; i++)
//            for (int j = 0; j < N; j++)
//            {
//                if (grid[i][j] == 0) continue;
//                if (grid[i][j] == 1) sTile.setTextureRect(IntRect(0, 0, ts, ts));
//                if (grid[i][j] == 2) sTile.setTextureRect(IntRect(54, 0, ts, ts));
//                sTile.setPosition(j * ts, i * ts);
//                window.draw(sTile);
//            }
//
//        sTile.setTextureRect(IntRect(36, 0, ts, ts));
//        sTile.setPosition(x * ts, y * ts);// drow the player
//        window.draw(sTile);
//
//        sEnemy.rotate(10);
//        for (int i = 0; i < enemyCount; i++)// drow the enemy
//        {
//            sEnemy.setPosition(a[i].x, a[i].y);
//            window.draw(sEnemy);
//        }
//
//        if (!Game) window.draw(sGameover);
//
//        window.display();
//    }
//
//    return 0;
//}
