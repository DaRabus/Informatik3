#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>



void generate_values(std::vector<int> &v, size_t num_values)
{
    v.clear();
    v.resize(num_values);
    std::iota(v.begin(), v.end(), 0);
    std::random_device rd;
    std::shuffle(v.begin(), v.end(), rd);
}



void visualize(const std::vector<int> &v)
{
    cv::Size img_size = cv::Size(40 * v.size(), 30 * v.size());
    cv::Mat img = cv::Mat::zeros(img_size, CV_8UC3);
    for (size_t i = 0; i < v.size(); i++)
    {
        int x = ((i + 1) * img_size.width) / (v.size() + 1);
        int y = img_size.height - 1 - ((v[i] * img_size.height) / v.size());
        cv::line(img,
            cv::Point(x, img_size.height - 1), cv::Point(x, y),
            cv::viz::Color::white(), 5, 8);
    }
    cv::imshow("Output", img);
    cv::waitKey(200);
}



void bubble_sort(std::vector<int> &v)
{
    for (int i = v.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
            visualize(v);
        }
    }
}



int main()
{
    const size_t num_values = 20;

    std::vector<int> v;
    generate_values(v, num_values);
    visualize(v);
    bubble_sort(v);

    return 0;
}
