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

	// TODO

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
