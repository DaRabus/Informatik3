#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>



int main()
{
    cv::Mat output = cv::Mat::zeros(cv::Size(800, 600), CV_8UC3);

	// Access single pixel
    output.at<cv::Vec3b>(cv::Point(790, 590)) = cv::viz::Color::white();


    // Single point
    // punkt1 , punkt 2, farbe, dicke strich,Linientyp(8punkt/4punk)
    cv::line(output, cv::Point(10, 10), cv::Point(390, 130), cv::Scalar(0, 255, 255), 5,8);

    // Circles with different diameters and line thicknesses (-1 = fill)
    cv::circle(output, cv::Point(200, 300), 100, cv::viz::Color::red(),    3, 8);
    cv::circle(output, cv::Point(200, 300),  75, cv::viz::Color::green(),  1, 8);
    cv::circle(output, cv::Point(200, 300),  50, cv::viz::Color::blue(),  -1, 8);
    /*


    // Rectangle defined by two cv::Point or by cv::Rect
    cv::rectangle(output, cv::Point(110, 110), cv::Point(190, 150), cv::viz::Color::yellow(), 2, 8);
    cv::rectangle(output, cv::Rect(100, 100, 100, 60), cv::viz::Color::apricot(), 1, 8);

	// Write text
    cv::putText(output, "Hello World :)", cv::Point(20, 500),
        cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(0, 100, 0), 4);
    cv::putText(output, "Hello World, again!", cv::Point(20, 550),
        cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 200, 0), 2);

    // Read image file and copy into image
    cv::Mat foot = cv::imread("/home/student/foot.png");
    if (!foot.data)
    {
        std::cout << "Unable to read image" << std::endl;
        return -1;
    }
    std::cout << "Image size is " << foot.size() << std::endl;
    foot.convertTo(foot, CV_8UC3);
    foot.copyTo(output(cv::Rect(600, 200, foot.cols, foot.rows)));
    */
    cv::imshow("MeineCW", output); //CW Window

	cv::waitKey(0);
	return 0;
}
