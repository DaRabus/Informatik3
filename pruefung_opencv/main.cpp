#include <opencv2/opencv.hpp>

void draw_grid(cv::Mat &img, size_t num_cols, size_t num_rows)
{


    int rowsline = img.rows/num_rows;
    for(int i=0 ; i != img.rows/num_rows ; i++){

      cv::line(img, cv::Point(rowsline, 0), cv::Point(rowsline, img.rows), cv::Scalar(0, 150, 255), 1,8);
       rowsline += img.rows/num_rows;

    }
    //int rowsline = img.rows/num_rows;
    int colsline = img.cols/num_cols;
    for(int i=0 ; i != img.cols/num_cols ; i++){

      cv::line(img, cv::Point(0, colsline), cv::Point(img.cols, colsline), cv::Scalar(0, 150, 255), 1,8);
       colsline += img.cols/num_cols;
    }
}

int main()
{
    cv::Mat img = cv::Mat(cv::Size(600,400), CV_8UC3,
        cv::Scalar(200, 200, 200));

    draw_grid(img, 6, 4);

//	cv::imwrite("grid.png", img);
    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}
