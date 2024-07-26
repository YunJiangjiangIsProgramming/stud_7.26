#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
// 这是一个C++程序，包含在std命名空间中

#include <vector>
#include <algorithm> // 用于sort函数
#include <limits> // 用于INT_MAX常量

// 定义Solution类
class Solution1 {
public:
    // findValueOfPartition方法计算整数数组中任意两个元素的最小差值
    int findValueOfPartition(std::vector<int>& nums) {
        // 使用STL的sort函数对nums数组进行排序
        // 排序后，数组中的元素将按升序排列
        std::sort(nums.begin(), nums.end());

        // 初始化最小差值为整数的最大值
        // 这样任何数组元素之间的差值都会小于这个初始值
        int minDifference = std::numeric_limits<int>::max();

        // 遍历排序后的数组，从第二个元素开始（因为我们需要计算与前一个元素的差值）
        for (size_t i = 1; i < nums.size(); ++i) {
            // 计算当前元素与前一个元素的差值，并更新最小差值
            minDifference = std::min(minDifference, nums[i] - nums[i - 1]);
        }

        // 返回最小差值
        return minDifference;
    }
};

void test1()
{
    std::vector<int> nums = { 10, 3, 2, 8, 15 };

    // 创建Solution类的实例
    Solution1 solution;

    // 调用findValueOfPartition方法，并打印返回的最小差值
    std::cout << "The minimum difference is: " << solution.findValueOfPartition(nums) << std::endl;
}

// 定义一个 C++ 中的点结构体
struct Point {
    double x;
    double y;

    // 点结构体的构造函数
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // 重载加法运算符来计算两个点的和
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // 计算点的模
    double magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // 输出点的信息
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "点的坐标 (" << p.x << ", " << p.y << ")";
        return os;
    }
};

// 计算绝对值的函数
double cal_abs(double x) {
    return (x > 0) ? x : -x;
}

int main() {
    // 创建几个点对象
    Point p1(3, 4);
    Point p2(1, 1);

    // 计算两个点的和
    Point p3 = p1 + p2;

    // 输出点的信息和模
    std::cout << p3 << " 的模是 " << p3.magnitude() << std::endl;

    // 输出绝对值
    for (int i = 1; i <= 5; ++i) {
        std::cout << "绝对值 of " << i << " 是 " << cal_abs(i) << std::endl;
    }
    test1();
    return 0;
}