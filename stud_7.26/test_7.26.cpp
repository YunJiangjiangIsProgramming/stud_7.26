#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
// ����һ��C++���򣬰�����std�����ռ���

#include <vector>
#include <algorithm> // ����sort����
#include <limits> // ����INT_MAX����

// ����Solution��
class Solution1 {
public:
    // findValueOfPartition��������������������������Ԫ�ص���С��ֵ
    int findValueOfPartition(std::vector<int>& nums) {
        // ʹ��STL��sort������nums�����������
        // ����������е�Ԫ�ؽ�����������
        std::sort(nums.begin(), nums.end());

        // ��ʼ����С��ֵΪ���������ֵ
        // �����κ�����Ԫ��֮��Ĳ�ֵ����С�������ʼֵ
        int minDifference = std::numeric_limits<int>::max();

        // �������������飬�ӵڶ���Ԫ�ؿ�ʼ����Ϊ������Ҫ������ǰһ��Ԫ�صĲ�ֵ��
        for (size_t i = 1; i < nums.size(); ++i) {
            // ���㵱ǰԪ����ǰһ��Ԫ�صĲ�ֵ����������С��ֵ
            minDifference = std::min(minDifference, nums[i] - nums[i - 1]);
        }

        // ������С��ֵ
        return minDifference;
    }
};

void test1()
{
    std::vector<int> nums = { 10, 3, 2, 8, 15 };

    // ����Solution���ʵ��
    Solution1 solution;

    // ����findValueOfPartition����������ӡ���ص���С��ֵ
    std::cout << "The minimum difference is: " << solution.findValueOfPartition(nums) << std::endl;
}

// ����һ�� C++ �еĵ�ṹ��
struct Point {
    double x;
    double y;

    // ��ṹ��Ĺ��캯��
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // ���ؼӷ������������������ĺ�
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // ������ģ
    double magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // ��������Ϣ
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "������� (" << p.x << ", " << p.y << ")";
        return os;
    }
};

// �������ֵ�ĺ���
double cal_abs(double x) {
    return (x > 0) ? x : -x;
}

int main() {
    // �������������
    Point p1(3, 4);
    Point p2(1, 1);

    // ����������ĺ�
    Point p3 = p1 + p2;

    // ��������Ϣ��ģ
    std::cout << p3 << " ��ģ�� " << p3.magnitude() << std::endl;

    // �������ֵ
    for (int i = 1; i <= 5; ++i) {
        std::cout << "����ֵ of " << i << " �� " << cal_abs(i) << std::endl;
    }
    test1();
    return 0;
}