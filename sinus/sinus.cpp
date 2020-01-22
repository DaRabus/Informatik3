#include <iostream>
#include <cmath>

#include <opencv2/opencv.hpp>



int main()
{
	// Create image of certain size
	cv::Size screenSize(800, 600);
	cv::Mat output = cv::Mat::zeros(screenSize, CV_8UC3);

	// Calculate points
	std::vector<cv::Point> points;
	for (int c = 0; c < screenSize.width; c++)
	{
		// c is in [0 .. (screenSize.width-1)]

		// x is in [0 .. 2*M_PI]
		double x = (2.0 * M_PI * c) / (screenSize.width - 1);

		// y is in [-1 .. 1]
        double y = sin(x);

		// r is in [(screenSize.height-1) .. 0]
		int r = round(((screenSize.height - 1) * (1.0 - y)) / 2.0);

		points.push_back(cv::Point(c, r));
	}

	// Draw (screenSize.width - 1) lines connecting the points
	for (int i = 1; i < screenSize.width; i++)
	{
		cv::line(output, points[i-1], points[i],
			cv::viz::Color::white(), 2, 8);
	}
	// Draw base line
	cv::line(output, cv::Point(0, screenSize.height / 2.0),
		cv::Point(screenSize.width - 1, screenSize.height / 2.0),
		cv::viz::Color::red(), 2, 8);

	// Show result and wait for key
	cv::imshow("Output", output);
	cv::waitKey(0);

	return 0;
}
