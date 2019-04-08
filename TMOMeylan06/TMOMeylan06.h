#include "TMO.h"
#include <math.h>
#include <algorithm>
#include <string>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

class TMOMeylan06 : public TMO
{
public:
	TMOMeylan06();
	virtual ~TMOMeylan06();
	virtual int Transform();

protected:
	TMODouble saturationParameter;
	int numberOfPixels;
	int numberOfPixelsRGB;
	cv::PCA pca;
	double kernelSize;
	double sigmaOrig;
	double sigmaEdge;
	cv::Mat RGBToPCA(double *rgbSourceData);
	cv::Mat PCAToRGB(cv::Mat &PCAProjection);
	cv::Mat GetEdges(cv::Mat &luminance, double upperThresholdRatio);
	cv::Mat DilatateEdges(cv::Mat &edges);
	cv::Mat GetMask(cv::Mat &luminance, cv::Mat &edges);
	double GetMaskVal(cv::Mat &luminance, cv::Mat &edges, cv::Mat &crossCounter, int x, int y, int counter);
	bool IsAnEdge(cv::Mat &edges, cv::Mat &crossCounter, int x, int y, int counter);
	double GaussDist(double d, double s);
	cv::Mat GetLuminance(cv::Mat &PCAProjection);
	void GlobalMapping(double* data, int dataLength, int numberOfChannels, std::string type);
	double ComputeAL(double *data, int dataLength, double scale);
	void HistoClip(double* data, int dataLength, int numberOfBuckets, double minThreshold, double maxThreshold);
	void ScaleRGB(double* data, double RScale, double GScale, double BScale);
	void LogMaxScale(double *data, int dataLength, double max, double scale);
	void Pow(double *data, int dataLength, double exponent);
	void Max(double *data, int dataLength, double max);
	void Min(double *data, int dataLength, double min);
	void Normalize(double *data, int dataLength);
	void Normalize(double *data, int dataLength, double lowerBound, double upperBound);
	double GetMax(double *data, int dataLength);
	double GetMin(double *data, int dataLength);
	void SaveImg(std::string name, double *data, bool RGB);
	cv::Mat ReshapeGray(cv::Mat &source);

};
