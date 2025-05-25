#include "TileBoard.h"
#include <iostream>
// בקובץ המחלקה:

TileBoard::TileBoard()
    :m_sizeTile(GameConsts::sizeTile)
{}

void TileBoard::initTileBoard(const sf::Vector2f& sizeWindow)
{
    m_sizeWindow = sizeWindow;
    m_rows = static_cast<int>((m_sizeWindow.y - GameConsts::HIGHT_SHAPE_INFO) / m_sizeTile.y);
    m_cols = static_cast<int>(m_sizeWindow.x / m_sizeTile.x);
    std::cout << m_rows << " " << m_cols;
    m_boardTile.clear();
    m_boardTile.resize(m_rows);

    for (int i = 0; i < m_rows; ++i) {
        m_boardTile[i].resize(m_cols);
        for (int j = 0; j < m_cols; ++j) {
            sf::Vector2f location(j * m_sizeTile.x, i * m_sizeTile.y);
            m_boardTile[i][j] = std::make_unique<Tile>(location, ObjectType::Empty); // יצירת תא בווקטור 

        }
    }
    markFrameTiles();     // לאחר מכן נעדכן את תאי המסגרת
}



void TileBoard::markFrameTiles() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            if (i == 0 || i == m_rows - 1 || j == 0 || j == m_cols - 1) {
                m_boardTile[i][j]->setType(ObjectType::Frame); // פה צריך לעדכן למזזה תמונה מסגרת
                //==============================================
            }
        }
    }
}


sf::Vector2f TileBoard::randLocation() const
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> rowDist(1, m_rows - 2); // לא בשוליים
    std::uniform_int_distribution<> colDist(1, m_cols - 2);

    int row = rowDist(gen);
    int col = colDist(gen);

    return sf::Vector2f(getTileLocByIndex(row, col)); // מיקום במסך לפי תא
}


void TileBoard::draw(sf::RenderWindow& window) {
    for (int row = 0; row < m_rows; row++) {
        for (int col = 0; col < m_cols; col++) {
            window.draw(m_boardTile[row][col]->getPicture());
        }
    }
}


sf::Vector2f TileBoard::getTileLoc(const sf::Vector2f& location)
{
    int col = static_cast <int> (location.x / m_sizeTile.x);
    int row = static_cast <int> (location.y / m_sizeTile.y);

    return getTileLocByIndex(col, row);
}

sf::Vector2f TileBoard::getTileLocByIndex(int cols, int rows) const
{
    return sf::Vector2f(cols * m_sizeTile.x, rows * m_sizeTile.y);
}



bool TileBoard::inArea(const sf::Vector2f& pos) const {
    int row = static_cast<int>(pos.y / GameConsts::sizeTile.y);
    int col = static_cast<int>(pos.x / GameConsts::sizeTile.x);

    return row >= 0 && col >= 0 &&
        row < static_cast<int>(m_boardTile.size()) &&
        col < static_cast<int>(m_boardTile[row].size());
}




bool TileBoard::isframeTile(const sf::Vector2f& location) const
{
    int col = static_cast<int>(location.x / m_sizeTile.x);
    int row = static_cast<int>(location.y / m_sizeTile.y);

    // בדיקת גבולות ראשוניתbool
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
        return false;

    // בדיקה לפי אינדקס מיקום בלוח
    return row == 0 || row == m_rows - 1 || col == 0 || col == m_cols - 1;
}





ObjectType TileBoard::getType(int row, int col) const
{
    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
        return m_boardTile[row][col]->getType();

    return ObjectType::Frame; // או None אם יש
}



Tile* TileBoard::getTile(const sf::Vector2f& location)
{
    int col = static_cast<int>(location.x / m_sizeTile.x);
    int row = static_cast<int>(location.y / m_sizeTile.y);

    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
        return m_boardTile[row][col].get();

    return nullptr; // מיקום לא חוקי
}


void TileBoard::restartTrail()
{
    for (int row = 0; row < m_rows; row++) {
        for (int col = 0; col < m_cols; col++) {
            if (m_boardTile[row][col]->getType() == ObjectType::Trail)
                m_boardTile[row][col]->setType(ObjectType::Empty);
        }
    }

}
ObjectType TileBoard::getTypeAtLocation(const sf::Vector2f& loc) const {
    int row = static_cast<int>(loc.y / m_sizeTile.y);
    int col = static_cast<int>(loc.x / m_sizeTile.x);

    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
        return m_boardTile[row][col]->getType();

    return ObjectType::Frame; // ערך ברירת מחדל
}



Tile& TileBoard::getTile(int row, int col)
{
    return *m_boardTile[row][col];
}

void TileBoard::markCapturedArea()
{
    for (int row = 0; row < m_rows; row++) {
        for (int col = 0; col < m_cols; col++) {
            Tile& tile = *m_boardTile[row][col];

            if (!tile.getIsVisited() && tile.getType() != ObjectType::Frame) {
                tile.setType(ObjectType::Filled); // תא שלא הגיעו אליו והוא ריק => סגור => למלא
            }
            tile.setVisited(false); // איפוס לכולם, כולל אלה שכן ביקרנו
        }
    }
}

bool TileBoard::isframeTileForMove(const sf::Vector2f& location) const
{
    int col = static_cast<int>(location.x / m_sizeTile.x);
    int row = static_cast<int>(location.y / m_sizeTile.y);

    // בדיקת גבולות ראשונית
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
        return false;

    // בדיקה לפי אינדקס מיקום בלוח
    return row == 0 || row == m_rows - 2 || col == 0 || col == m_cols - 2;
}

//bool TileBoard::inAreaMove(const sf::Vector2f& pos) const
//{
//    return pos.x >= 0 && pos.y >= 0 && pos.x <= 585.f && pos.y <= 585.f;
//}




