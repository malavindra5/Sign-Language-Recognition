#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

class Group{
	public:
		string first;
		double *second;
		double third;
};

double dist(double *a, double *b);
bool comp(Group a, Group b);
bool comp2(pair<int, string> a, pair<int, string> b);

int main(int argc, char** argv){
	VideoCapture cap(0);
	
	if(!cap.isOpened()){
		return -1;
	}
	
	Mat frame, image, roiFrame, roiImage;
	
	int n = 144;
	Group p[n];
	
	for(int i = 0; i < n; i++){
		
		switch(i){
			case 0:
				image = imread("Pradeep/a1.JPG");
				p[i].first = "A";
				break;
			case 1:
				image = imread("Pradeep/a2.JPG");
				p[i].first = "A";
				break;
			case 2:
				image = imread("Pradeep/a3.JPG");
				p[i].first = "A";
				break;
			case 3:
				image = imread("Pradeep/b1.JPG");
				p[i].first = "B";
				break;
			case 4:
				image = imread("Pradeep/b2.JPG");
				p[i].first = "B";
				break;
			case 5:
				image = imread("Pradeep/b3.JPG");
				p[i].first = "B";
				break;
			case 6:
				image = imread("Pradeep/c1.JPG");
				p[i].first = "C";
				break;
			case 7:
				image = imread("Pradeep/c2.JPG");
				p[i].first = "C";
				break;
			case 8:
				image = imread("Pradeep/c3.JPG");
				p[i].first = "C";
				break;
			case 9:
				image = imread("Pradeep/d1.JPG");
				p[i].first = "D";
				break;
			case 10:
				image = imread("Pradeep/d2.JPG");
				p[i].first = "D";
				break;
			case 11:
				image = imread("Pradeep/d3.JPG");
				p[i].first = "D";
				break;
			case 12:
				image = imread("Pradeep/f1.JPG");
				p[i].first = "F";
				break;
			case 13:
				image = imread("Pradeep/f2.JPG");
				p[i].first = "F";
				break;
			case 14:
				image = imread("Pradeep/f3.JPG");
				p[i].first = "F";
				break;
			case 15:
				image = imread("Pradeep/i1.JPG");
				p[i].first = "I";
				break;
			case 16:
				image = imread("Pradeep/i2.JPG");
				p[i].first = "I";
				break;
			case 17:
				image = imread("Pradeep/i3.JPG");
				p[i].first = "I";
				break;
			case 18:
				image = imread("Pradeep/l1.JPG");
				p[i].first = "L";
				break;
			case 19:
				image = imread("Pradeep/l2.JPG");
				p[i].first = "L";
				break;
			case 20:
				image = imread("Pradeep/l3.JPG");
				p[i].first = "L";
				break;
			case 21:
				image = imread("Pradeep/o1.JPG");
				p[i].first = "O";
				break;
			case 22:
				image = imread("Pradeep/o2.JPG");
				p[i].first = "O";
				break;
			case 23:
				image = imread("Pradeep/o3.JPG");
				p[i].first = "O";
				break;
			case 24:
				image = imread("Pradeep/u1.JPG");
				p[i].first = "U";
				break;
			case 25:
				image = imread("Pradeep/u2.JPG");
				p[i].first = "U";
				break;
			case 26:
				image = imread("Pradeep/u3.JPG");
				p[i].first = "U";
				break;
			case 27:
				image = imread("Pradeep/v1.JPG");
				p[i].first = "V";
				break;
			case 28:
				image = imread("Pradeep/v2.JPG");
				p[i].first = "V";
				break;
			case 29:
				image = imread("Pradeep/v3.JPG");
				p[i].first = "V";
				break;
			case 30:
				image = imread("Pradeep/w1.JPG");
				p[i].first = "W";
				break;
			case 31:
				image = imread("Pradeep/w2.JPG");
				p[i].first = "W";
				break;
			case 32:
				image = imread("Pradeep/w3.JPG");
				p[i].first = "W";
				break;
			case 33:
				image = imread("Pradeep/y1.JPG");
				p[i].first = "Y";
				break;
			case 34:
				image = imread("Pradeep/y2.JPG");
				p[i].first = "Y";
				break;
			case 35:
				image = imread("Pradeep/y3.JPG");
				p[i].first = "Y";
				break;
			case 36:
				image = imread("Pradeep/e1.JPG");
				p[i].first = "E";
				break;
			case 37:
				image = imread("Pradeep/e2.JPG");
				p[i].first = "E";
				break;
			case 38:
				image = imread("Pradeep/e3.JPG");
				p[i].first = "E";
				break;
			case 39:
				image = imread("Pradeep/g1.JPG");
				p[i].first = "G";
				break;
			case 40:
				image = imread("Pradeep/g2.JPG");
				p[i].first = "G";
				break;
			case 41:
				image = imread("Pradeep/g3.JPG");
				p[i].first = "G";
				break;
			case 42:
				image = imread("Pradeep/h1.JPG");
				p[i].first = "H";
				break;
			case 43:
				image = imread("Pradeep/h2.JPG");
				p[i].first = "H";
				break;
			case 44:
				image = imread("Pradeep/h3.JPG");
				p[i].first = "H";
				break;
			case 45:
				image = imread("Pradeep/k1.JPG");
				p[i].first = "K";
				break;
			case 46:
				image = imread("Pradeep/k2.JPG");
				p[i].first = "K";
				break;
			case 47:
				image = imread("Pradeep/k3.JPG");
				p[i].first = "K";
				break;
			case 48:
				image = imread("Pradeep/m1.JPG");
				p[i].first = "M";
				break;
			case 49:
				image = imread("Pradeep/m2.JPG");
				p[i].first = "M";
				break;
			case 50:
				image = imread("Pradeep/m3.JPG");
				p[i].first = "M";
				break;
			case 51:
				image = imread("Pradeep/n1.JPG");
				p[i].first = "N";
				break;
			case 52:
				image = imread("Pradeep/n2.JPG");
				p[i].first = "N";
				break;
			case 53:
				image = imread("Pradeep/n3.JPG");
				p[i].first = "N";
				break;
			case 54:
				image = imread("Pradeep/p1.JPG");
				p[i].first = "P";
				break;
			case 55:
				image = imread("Pradeep/p2.JPG");
				p[i].first = "P";
				break;
			case 56:
				image = imread("Pradeep/p3.JPG");
				p[i].first = "P";
				break;
			case 57:
				image = imread("Pradeep/r1.JPG");
				p[i].first = "R";
				break;
			case 58:
				image = imread("Pradeep/r2.JPG");
				p[i].first = "R";
				break;
			case 59:
				image = imread("Pradeep/r3.JPG");
				p[i].first = "R";
				break;
			case 60:
				image = imread("Pradeep/s1.JPG");
				p[i].first = "S";
				break;
			case 61:
				image = imread("Pradeep/s2.JPG");
				p[i].first = "S";
				break;
			case 62:
				image = imread("Pradeep/s3.JPG");
				p[i].first = "S";
				break;
			case 63:
				image = imread("Pradeep/t1.JPG");
				p[i].first = "T";
				break;
			case 64:
				image = imread("Pradeep/t2.JPG");
				p[i].first = "T";
				break;
			case 65:
				image = imread("Pradeep/t3.JPG");
				p[i].first = "T";
				break;
			case 66:
				image = imread("Pradeep/x1.JPG");
				p[i].first = "X";
				break;
			case 67:
				image = imread("Pradeep/x2.JPG");
				p[i].first = "X";
				break;
			case 68:
				image = imread("Pradeep/x3.JPG");
				p[i].first = "X";
				break;
			case 69:
				image = imread("Pradeep/space1.JPG");
				p[i].first = " ";
				break;
			case 70:
				image = imread("Pradeep/space2.JPG");
				p[i].first = " ";
				break;
			case 71:
				image = imread("Pradeep/space3.JPG");
				p[i].first = " ";
				break;
			case 72:
				image = imread("Indra/a1.JPG");
				p[i].first = "A";
				break;
			case 73:
				image = imread("Indra/a2.JPG");
				p[i].first = "A";
				break;
			case 74:
				image = imread("Indra/a3.JPG");
				p[i].first = "A";
				break;
			case 75:
				image = imread("Indra/b1.JPG");
				p[i].first = "B";
				break;
			case 76:
				image = imread("Indra/b2.JPG");
				p[i].first = "B";
				break;
			case 77:
				image = imread("Indra/b3.JPG");
				p[i].first = "B";
				break;
			case 78:
				image = imread("Indra/c1.JPG");
				p[i].first = "C";
				break;
			case 79:
				image = imread("Indra/c2.JPG");
				p[i].first = "C";
				break;
			case 80:
				image = imread("Indra/c3.JPG");
				p[i].first = "C";
				break;
			case 81:
				image = imread("Indra/d1.JPG");
				p[i].first = "D";
				break;
			case 82:
				image = imread("Indra/d2.JPG");
				p[i].first = "D";
				break;
			case 83:
				image = imread("Indra/d3.JPG");
				p[i].first = "D";
				break;
			case 84:
				image = imread("Indra/f1.JPG");
				p[i].first = "F";
				break;
			case 85:
				image = imread("Indra/f2.JPG");
				p[i].first = "F";
				break;
			case 86:
				image = imread("Indra/f3.JPG");
				p[i].first = "F";
				break;
			case 87:
				image = imread("Indra/i1.JPG");
				p[i].first = "I";
				break;
			case 88:
				image = imread("Indra/i2.JPG");
				p[i].first = "I";
				break;
			case 89:
				image = imread("Indra/i3.JPG");
				p[i].first = "I";
				break;
			case 90:
				image = imread("Indra/l1.JPG");
				p[i].first = "L";
				break;
			case 91:
				image = imread("Indra/l2.JPG");
				p[i].first = "L";
				break;
			case 92:
				image = imread("Indra/l3.JPG");
				p[i].first = "L";
				break;
			case 93:
				image = imread("Indra/o1.JPG");
				p[i].first = "O";
				break;
			case 94:
				image = imread("Indra/o2.JPG");
				p[i].first = "O";
				break;
			case 95:
				image = imread("Indra/o3.JPG");
				p[i].first = "O";
				break;
			case 96:
				image = imread("Indra/u1.JPG");
				p[i].first = "U";
				break;
			case 97:
				image = imread("Indra/u2.JPG");
				p[i].first = "U";
				break;
			case 98:
				image = imread("Indra/u3.JPG");
				p[i].first = "U";
				break;
			case 99:
				image = imread("Indra/v1.JPG");
				p[i].first = "V";
				break;
			case 100:
				image = imread("Indra/v2.JPG");
				p[i].first = "V";
				break;
			case 101:
				image = imread("Indra/v3.JPG");
				p[i].first = "V";
				break;
			case 102:
				image = imread("Indra/w1.JPG");
				p[i].first = "W";
				break;
			case 103:
				image = imread("Indra/w2.JPG");
				p[i].first = "W";
				break;
			case 104:
				image = imread("Indra/w3.JPG");
				p[i].first = "W";
				break;
			case 105:
				image = imread("Indra/y1.JPG");
				p[i].first = "Y";
				break;
			case 106:
				image = imread("Indra/y2.JPG");
				p[i].first = "Y";
				break;
			case 107:
				image = imread("Indra/y3.JPG");
				p[i].first = "Y";
				break;
			case 108:
				image = imread("Indra/e1.JPG");
				p[i].first = "E";
				break;
			case 109:
				image = imread("Indra/e2.JPG");
				p[i].first = "E";
				break;
			case 110:
				image = imread("Indra/e3.JPG");
				p[i].first = "E";
				break;
			case 111:
				image = imread("Indra/g1.JPG");
				p[i].first = "G";
				break;
			case 112:
				image = imread("Indra/g2.JPG");
				p[i].first = "G";
				break;
			case 113:
				image = imread("Indra/g3.JPG");
				p[i].first = "G";
				break;
			case 114:
				image = imread("Indra/h1.JPG");
				p[i].first = "H";
				break;
			case 115:
				image = imread("Indra/h2.JPG");
				p[i].first = "H";
				break;
			case 116:
				image = imread("Indra/h3.JPG");
				p[i].first = "H";
				break;
			case 117:
				image = imread("Indra/k1.JPG");
				p[i].first = "K";
				break;
			case 118:
				image = imread("Indra/k2.JPG");
				p[i].first = "K";
				break;
			case 119:
				image = imread("Indra/k3.JPG");
				p[i].first = "K";
				break;
			case 120:
				image = imread("Indra/m1.JPG");
				p[i].first = "M";
				break;
			case 121:
				image = imread("Indra/m2.JPG");
				p[i].first = "M";
				break;
			case 122:
				image = imread("Indra/m3.JPG");
				p[i].first = "M";
				break;
			case 123:
				image = imread("Indra/n1.JPG");
				p[i].first = "N";
				break;
			case 124:
				image = imread("Indra/n2.JPG");
				p[i].first = "N";
				break;
			case 125:
				image = imread("Indra/n3.JPG");
				p[i].first = "N";
				break;
			case 126:
				image = imread("Indra/p1.JPG");
				p[i].first = "P";
				break;
			case 127:
				image = imread("Indra/p2.JPG");
				p[i].first = "P";
				break;
			case 128:
				image = imread("Indra/p3.JPG");
				p[i].first = "P";
				break;
			case 129:
				image = imread("Indra/r1.JPG");
				p[i].first = "R";
				break;
			case 130:
				image = imread("Indra/r2.JPG");
				p[i].first = "R";
				break;
			case 131:
				image = imread("Indra/r3.JPG");
				p[i].first = "R";
				break;
			case 132:
				image = imread("Indra/s1.JPG");
				p[i].first = "S";
				break;
			case 133:
				image = imread("Indra/s2.JPG");
				p[i].first = "S";
				break;
			case 134:
				image = imread("Indra/s3.JPG");
				p[i].first = "S";
				break;
			case 135:
				image = imread("Indra/t1.JPG");
				p[i].first = "T";
				break;
			case 136:
				image = imread("Indra/t2.JPG");
				p[i].first = "T";
				break;
			case 137:
				image = imread("Indra/t3.JPG");
				p[i].first = "T";
				break;
			case 138:
				image = imread("Indra/x1.JPG");
				p[i].first = "X";
				break;
			case 139:
				image = imread("Indra/x2.JPG");
				p[i].first = "X";
				break;
			case 140:
				image = imread("Indra/x3.JPG");
				p[i].first = "X";
				break;
			case 141:
				image = imread("Indra/space1.JPG");
				p[i].first = " ";
				break;
			case 142:
				image = imread("Indra/space2.JPG");
				p[i].first = " ";
				break;
			case 143:
				image = imread("Indra/space3.JPG");
				p[i].first = " ";
				break;
			default:
				cout << "Reached default case!!" << endl;
				break;
		}
		
		Rect roi = Rect(210, 160, 350, 350);
		roiImage = image(roi);
		cvtColor(roiImage, roiImage, CV_BGR2GRAY);
		GaussianBlur(roiImage, roiImage, Size(5,5), 0, 0);
		threshold(roiImage, roiImage, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);
		p[i].second = new double[7];
		
		HuMoments(moments(roiImage), p[i].second);
		
		//imshow("ROI", roiImage);
		//waitKey(0);
	}
	
	string sentence = "";
	vector<string> alpha;
	string nCharText = "No. of characters: ";
	int nChar = 0;
	string nCharStr;
	pair<int, string> count[27];
	for(int i = 0; i < 27; i++){
		count[i].first = 0;
	}
	count[0].second = " ";
	count[1].second = "A";
	count[2].second = "B";
	count[3].second = "C";
	count[4].second = "D";
	count[5].second = "E";
	count[6].second = "F";
	count[7].second = "G";
	count[8].second = "H";
	count[9].second = "I";
	count[10].second = "J";
	count[11].second = "K";
	count[12].second = "L";
	count[13].second = "M";
	count[14].second = "N";
	count[15].second = "O";
	count[16].second = "P";
	count[17].second = "Q";
	count[18].second = "R";
	count[19].second = "S";
	count[20].second = "T";
	count[21].second = "U";
	count[22].second = "V";
	count[23].second = "W";
	count[24].second = "X";
	count[25].second = "Y";
	count[26].second = "Z";
	int nFrames = 0;
	
	while(true){
		cap >> frame;
		
		Rect roi1 = Rect(50, 50, 350, 350);
		roiFrame = frame(roi1);
		
		cvtColor(roiFrame, roiFrame, CV_BGR2GRAY);
		
		GaussianBlur(roiFrame, roiFrame, Size(5,5), 0, 0);
		threshold(roiFrame, roiFrame, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);
		
		double huFrame[7];
		
		HuMoments(moments(roiFrame), huFrame);
		
		for(int i = 0; i < n; i++){
			p[i].third = dist(huFrame, p[i].second);
		}
		
		sort(p, p+n, comp);
		nFrames++;
		if(nFrames > 100){
			nFrames = 0;
			sort(count, count + 27, comp2);
			if(count[0].first > 50){
				cout << '\a';
				if(alpha.size() > 0 && count[0].second == "V"){
					alpha.erase(alpha.begin() + nChar-1);
					nChar--;
				}else{
					alpha.push_back(count[0].second);
					nChar++;
				}
			}
			for(int i = 0; i < 27; i++){
				count[i].first = 0;
			}
		}
		
		for(int i = 0; i < 27; i++){
			if(count[i].second == p[0].first){
				count[i].first++;
			}
		}
		
		rectangle(frame, cvPoint(685,20), cvPoint(825,50), cvScalar(0,0,0), CV_FILLED);
		
		if(p[0].first == "V"){
			putText(frame, "Backspace", cvPoint(700,40), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(255,255,255), 1, CV_AA);
		}
		else if(p[0].first == " "){
			putText(frame, "Whitespace", cvPoint(700,40), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(255,255,255), 1, CV_AA);
		}
		else{
			putText(frame, "Alphabet " + p[0].first, cvPoint(700,40), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(255,255,255), 1, CV_AA);
		}
		
		stringstream s;
		s << nChar;
		nCharStr = s.str();
		
		sentence = "";
		for(int i = 0; i < alpha.size(); i++){
			sentence += alpha[i];
		}
		
		rectangle(frame, cvPoint(0,448), cvPoint(850,478), cvScalar(0,0,0), CV_FILLED);
		putText(frame, sentence, cvPoint(15,468), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(255,255,255), 1, CV_AA);
		rectangle(frame, cvPoint(625,68), cvPoint(850,98), cvScalar(0,0,0), CV_FILLED);
		putText(frame, nCharText + nCharStr, cvPoint(635,88), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(255,255,255), 1, CV_AA);
		
		imshow("Output", frame);
		imshow("ROI", roiFrame);
		
		if(waitKey(27) == 27){
			break;
		}
	}
	
	return 0;
}

double dist(double *a, double *b){
	double d = 0;
	for(int i = 0; i < 7; i++){
		if(a[i] > b[i]){
			d += pow(a[i]/b[i], 50);
		}else{
			d += pow(b[i]/a[i], 50);
		}
	}
	return abs(d-7)/7;
}

bool comp(Group a, Group b){
	return a.third < b.third;
}

bool comp2(pair<int, string> a, pair<int, string> b){
	return a.first > b.first;
}

