#ifndef QUAD_INCLUDE
#define QUAD_INCLUDE

#include "config.h"

#include "ofMain.h"
#include "ofGraphics.h"

#ifdef WITH_KINECT
#include "ofxOpenCv.h"
#include "kinectManager.h"
#endif

#ifdef WITH_SYPHON
#include "ofxSyphon.h"
#endif

class quad: public ofNode
{

public:
    quad();
    void reset();
    void setup(ofPoint point1, ofPoint point2, ofPoint point3, ofPoint point4, ofShader &edgeBlendShader, ofShader &quadMaskShader, ofShader &chromaShader, ofShader &hueSatLumShader, ofShader &fadeShader, vector<ofVideoGrabber> &cameras, vector<ofVideoPlayer> &sharedVideos, ofTrueTypeFont &font);
    void update();
    void draw();
    void applyBlendmode();
    void gaussian_elimination(float *input, int n);
    void findHomography(ofPoint src[4], ofPoint dst[4], float homography[16]);
    ofMatrix4x4 findVectorHomography(ofPoint src[4], ofPoint dst[4]);
    ofPoint findWarpedPoint(ofPoint src[4], ofPoint dst[4], ofPoint point);
    void loadImageFromFile(string imgName, string imgPath);
    void loadVideoFromFile(string videoName, string videoPath);
    void allocateFbo(int w, int h);
    void maskAddPoint(ofPoint point);
    void drawMaskMarkers();
    void bezierSurfaceSetup();
    void bezierSurfaceUpdate();
    void drawBezierMarkers();
    void setupCamera();
    int getdir (string dir, vector<string> &files); // a func for reading a dir content to a vector of strings
    ofPoint getWarpedPoint(ofPoint point);
    void gridSurfaceSetup();
    void gridSurfaceUpdate();
    void drawGridMarkers();

    #ifdef WITH_KINECT
    void setKinect(kinectManager &kinect);
    #endif

    #ifdef WITH_SYPHON
    void setSyphon(ofxSyphonClient &syphon);
    #endif

    ofPoint corners[4];
    ofPoint center;

    ofPoint src[4];
    ofPoint dst[4];
    float crop[4];
    float circularCrop[3];

    GLfloat matrix[16]; //lets make a matrix for openGL - this will be the matrix that peforms the transformation

    /* img and video stuff */
    ofImage img;
//    ofImage slide;
    ofImage nextSlide;
    ofVideoPlayer video;
    ofTrueTypeFont ttf;

    int videoWidth;
    int videoHeight;

    ofFloatColor bgColor;
    ofFloatColor secondColor;
    ofFloatColor startColor;
    ofFloatColor endColor;
    ofFloatColor transColor;
    ofFloatColor imgColorize;
    ofFloatColor videoColorize;
    ofFloatColor camColorize;
    ofFloatColor colorGreenscreen;
    ofFloatColor kinectColorize;
    ofFloatColor timelineColor;

    float timelineRed;
    float timelineGreen;
    float timelineBlue;
    float timelineAlpha;

    bool bTimelineColor;
    bool bTimelineTint;
    bool bTimelineAlpha;
    bool bTimelineSlideChange;

    int bgAlpha;

    /* camera stuff */
    bool camAvailable;
    int camWidth;
    int camHeight;
    int camNumber;
    int prevCamNumber;

    int layer;

    float screenFactorX;
    float screenFactorY;
    float camMultX;
    float camMultY;
    float imgMultX;
    float imgMultY;
    float kinectMultX;
    float kinectMultY;
    float videoMultX;
    float videoMultY;
    float videoSpeed;
    float previousSpeed;
    float slideshowSpeed;
    float transDuration;
    float edgeBlendExponent;
    float edgeBlendAmountSin;
    float edgeBlendAmountDx;
    float edgeBlendAmountTop;
    float edgeBlendAmountBottom;
    float edgeBlendGamma;
    float edgeBlendLuminance;

    int quadNumber;

    bool initialized;
    bool isActive;
    bool isSetup;
    bool isOn;
    bool isMaskSetup;
    bool colorBg;
    bool transBg;
    bool transUp;
    bool camBg;
    bool camGreenscreen;
    bool imgBg;
    bool videoBg;
    bool videoSound;
    bool videoLoop;
    bool videoGreenscreen;
    bool sharedVideoBg;
    int sharedVideoNum;
    int sharedVideoId;
    bool slideshowBg;
    bool slideFit;
    bool slideKeepAspect;
    bool bFadeTransitions;
    bool imageFit;
    bool imageKeepAspect;
    bool kinectBg;
    bool kinectImg;
    bool kinectMask;
    int nearDepthTh;
    int farDepthTh;
    int kinectBlur;
    float kinectContourMin;
    float kinectContourMax;
    float kinectContourSimplify;
    int kinectContourSmooth;
    bool getKinectContours;
    bool getKinectGrayImage;
    bool kinectContourCurved;

    bool videoHFlip;
    bool imgHFlip;
    bool camHFlip;
    bool videoVFlip;
    bool imgVFlip;
    bool camVFlip;
    bool edgeBlendBool;

    bool bBlendModes;
    int blendMode;

    bool bMask;
    bool maskInvert;
    int maskMode;
    bool bDrawMaskOutline;

    bool bHighlightCorner;
    int highlightedCorner;

    bool bHighlightCenter;
    bool bHighlightRotation;

    float videoVolume;
    float thresholdGreenscreen;
    int bgSlideshow;
    unsigned int currentSlide;
    int transStep;
    int transCounter;
    int fps;
    int slideFramesDuration;
    int slideTimer;

    vector<string> videos;
    //vector<string> slideshows;
    vector<string> slidesnames;
    vector<ofImage> slides;
    vector<ofVideoGrabber> cams;
    vector<ofVideoPlayer> vids;

    string bgImg;
    string bgVideo;
    string loadedImg;
    string loadedVideo;
    string loadedSlideshow;
    string slideshowName;

    // FBO's
    ofFbo quadFbo;
    ofFbo maskFbo;
    ofFbo targetFbo;
    ofFbo::Settings settings;
    ofFbo::Settings maskFboSettings;

    // Shaders
    ofShader * shaderBlend;
    ofShader * maskShader;
    ofShader * greenscreenShader;
    ofShader * hueSatLuminanceShader;
    ofShader * crossfadeShader;

    float hue;
    float saturation;
    float luminance;

    int quadDispX;
    int quadDispY;
    int quadW;
    int quadH;

    std::vector<ofPoint> m_maskPoints;
    bool bHighlightMaskPoint;
    int highlightedMaskPoint;

    bool bDeform;

    bool isBezierSetup;
    bool bHighlightCtrlPoint;
    int highlightedCtrlPointRow;
    int highlightedCtrlPointCol;
    float bezierPoints[4][4][3];
    bool bBezier;
    float bezierCtrlPoints[4][4][3];

    bool bGrid;
    vector<vector<vector<float> > > gridPoints;
    //vector<GLfloat> gridCtrlPoints;
    int gridRows;
    int gridColumns;
    ofMesh gridMesh;

    #ifdef WITH_KINECT
    kinectManager * quadKinect;
    ofxCvGrayscaleImage kinectThreshImage;
    ofxCvGrayscaleImage kinectContourImage;
    ofxCvContourFinder kinectContourFinder;
    ofPath kinectPath;
    #endif

    #ifdef WITH_SYPHON
    ofxSyphonClient * syphClientTex;
    bool bSyphon;
    float syphonPosX;
    float syphonPosY;
    float syphonScaleX;
    float syphonScaleY;
    #endif


};

#endif //QUAD_INCLUDE

