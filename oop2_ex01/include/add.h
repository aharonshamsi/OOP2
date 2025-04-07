#include "BaseOperation.h"
#include <memory>

class Add : public BaseOperation {
public:
    Add(std::shared_ptr<BaseOperation> op1, std::shared_ptr<BaseOperation> op2)
        : BaseOperation("Add(" + op1->getName() + ", " + op2->getName() + ")"), m_op1(op1), m_op2(op2) {}

    void execute(std::shared_ptr<SquareMatrix> matrix) override {
        // יצירת עותק של המטריצה לפני ביצוע כל פעולה
        auto matrix1 = std::make_shared<SquareMatrix>(*matrix);
        auto matrix2 = std::make_shared<SquareMatrix>(*matrix);

        // הפעלת הפעולה הראשונה על המטריצה הראשונה
        m_op1->execute(matrix1);
        // הפעלת הפעולה השנייה על המטריצה השנייה
        m_op2->execute(matrix2);

        // חיבור המטריצות
        for (int i = 0; i < matrix->getSize(); ++i) {
            for (int j = 0; j < matrix->getSize(); ++j) {
                int sum = matrix1->getMatrix(i, j) + matrix2->getMatrix(i, j);
                matrix->setValue(i, j, sum);  // עדכון המטריצה המקורית
            }
        }
    }
    std::shared_ptr<BaseOperation> getOp1() const { return m_op1; }
    std::shared_ptr<BaseOperation> getOp2() const { return m_op2; }

private:
    std::shared_ptr<BaseOperation> m_op1;
    std::shared_ptr<BaseOperation> m_op2;
};
