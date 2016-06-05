#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()
{
    Mat image=imread("D:/image/me.jpg",1);
    imshow("src image",image);

    Mat filter1;
    /*
     * Blurs an image using the box filter.
       C++: void boxFilter(InputArray src, OutputArray dst, int ddepth,
            Size ksize, Point anchor=Point(-1,-1),
            bool normalize=true,int borderType=BORDER_DEFAULT )
    */
    boxFilter(image,filter1,-1,Size(20,20));
    imshow("box filter",filter1);

    Mat filter2;

    //若sigmaX=sigmaY=0,则实际用的是公式sigma = 0.3*((ksize-1)*0.5 - 1) + 0.8,所以这里是0.8
    GaussianBlur(image,filter2,Size(3,3),5,1);
    imshow("gaussian filter",filter2);

    Mat filter3;
    Laplacian(image,filter3,-1,1,1,0,BORDER_DEFAULT);
    imshow("laplacian filter",filter3);
    //加绝对值
    Mat final;
    convertScaleAbs(filter3,final);
    imshow("laplacian final filter",final);

    waitKey(0);
    destroyAllWindows();
    image.release();
    filter1.release();
    filter2.release();
    filter3.release();
    final.release();

}
