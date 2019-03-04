#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
	ofRotate(270);

	for (int radius = 50; radius < 350; radius += 50) {

		int deg_start = ofGetFrameNum() + radius;
		for (int i = 0; i < 2; i++) {

			for (int deg = deg_start; deg < deg_start + 360; deg += 120) {

				vector<glm::vec2> vertices;
				for (int tmp_deg = deg; tmp_deg <= deg + 80; tmp_deg += 1) {

					vertices.push_back(glm::vec2(this->make_point(radius, tmp_deg)));
				}

				ofFill();
				ofSetColor(39);
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);

				ofNoFill();
				ofSetColor(239);
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);
			}

			ofRotate(180);
		}
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int radius, int deg) {

	deg = deg % 360;

	int deg_a = (deg / 120) * 120;
	int deg_b = deg_a + 120;

	int remainder = deg % 120;
	int diff = deg - deg_a;

	auto point_a = glm::vec2(radius * cos(deg_a * DEG_TO_RAD), radius * sin(deg_a * DEG_TO_RAD));
	auto point_b = glm::vec2(radius * cos(deg_b * DEG_TO_RAD), radius * sin(deg_b * DEG_TO_RAD));
	auto distance = point_b - point_a;

	return point_a + (distance / 120) * diff;
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}