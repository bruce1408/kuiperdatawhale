/*
 * @Author: BruceCui 
 * @Date: 2024-10-13 14:50:44 
 * @Last Modified by:   BruceCui 
 * @Last Modified time: 2024-10-13 14:50:44 
 */

#include <armadillo>
#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(test_arma, add) {
    using namespace arma;

    fmat in_matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    fmat in_matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    fmat out_matrix1 = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };
    
    fmat out_matrix2 = in_matrix1 + in_matrix2;
    ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}

TEST(test_arma, sub) {
    using namespace arma;
    fmat in_matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    fmat in_matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    const fmat& out_matrix1 = fmat(3, 3, fill::zeros); // OK，临时对象可以绑定到 const 引用
    
    // 不推荐这么写，列表初始化无法推导出具体的类型，可能部分编译器会报错;
    // 因为编译器需要从{}列表中推断出具体的类型，然而，列表初始化是通用的，可能代表多种类型，无法推断出想要的类型
    // const fmat& output_matrix1 = {
    //     {0, 0, 0},
    //     {0, 0, 0},
    //     {0, 0, 0
    // }


    const fmat& out_matrix2 = in_matrix1 - in_matrix2;
    ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}

TEST(test_arma, matmul) {
    using namespace arma;
    fmat in_matrix1 ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    fmat in_matrix2 ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    const fmat &out_matrix1 = {
        {30, 36, 42},
        {66, 81, 96},
        {102, 126, 150}
    };

    const fmat &out_matrix2 = in_matrix1 * in_matrix2;
    ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}

TEST(test_arma, pointwise) {
    using namespace arma;
    fmat in_matrix1 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";


    fmat in_matrix2 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

    const fmat &out_matrix1 = "1,4,9;"
                            "16,25,36;"
                            "49,64,81;";

    const fmat &out_matrix2 = in_matrix1 % in_matrix2;
    ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}