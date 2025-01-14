#include "main.h"
//~~~~~~ Class Includes ~~~~~~//
#include "groupIncludes.h"
#include "groupTestIncludes.h"

int main(int argc, char** argv) {
    fileName = malloc(sizeof(char) * 10);
    strcpy(fileName, "shape.txt");

    // Run tests if need be
    if (argc == 2 && strcmp(argv[1], "-t") == 0) {
        runAllTests();
    } else {
        //~~~~~ Group 1 ~~~~~//
        inputShape = readInput(fileName);

        //~~~~~ Group 2 ~~~~~//
        void globalScaling();

        //~~~~~ Group 3 ~~~~~//
        void xScaling();

        //~~~~~ Group 4 ~~~~~//
        void yScaling();

        //~~~~~ Group 5 ~~~~~//
        void zScaling();

        //~~~~~ Group 6 ~~~~~//
        void xRotation();

        //~~~~~ Group 7 ~~~~~//
        void yRotation();

        //~~~~~ Group 8 ~~~~~//
        void zRotation();

        //~~~~~ Group 9 ~~~~~//
        void xyzTranslation();

        //~~~~~ Group 10 ~~~~~//
        void xPlaneReflection();

        //~~~~~ Group 11 ~~~~~//
        void yPlaneReflection();

        //~~~~~ Group 12 ~~~~~//
        void zPlaneReflection();

        //~~~~~ Group 13 ~~~~~//
        void xShear();

        //~~~~~ Group 14 ~~~~~//
        void yShear();

        //~~~~~ Group 15 ~~~~~//
        void zShear();

        //~~~~~ Group 16 ~~~~~//
        void xyzOrthographicProjection();

        //~~~~~ Group 17 ~~~~~//
        int outputPoint(struct point * finalPoint, char* filename);

        free(inputShape);
    }
    free(fileName);
    return 0;
}

// ~~~~~~~~~~~~~~~~~ Getters ~~~~~~~~~~~~~~~~~~~ //

struct point* getPoint(int index) {
    // if the index is less then 0 or greater the the number of points, or the points are null
    if ((index < 0) || (index >= inputShape->numOfPoints) || inputShape->points == NULL) {
        // return null
        return NULL;
    }

    // otherwise return the point at the index
    return inputShape->points[index];
}

// ~~~~~~~~~~~~~~~~~ GROUP Getters Go HERE ~~~~~~~~~~~~~~~~~~~ //
float getGloalScale() {
    return 0;
}

float getXScale() {
    return inputShape -> scaling[0];
}

float getYScale() {
    return 0;
}

float getZScale() {
    return 0;
}

float getXRotation() {
    return 0;
}

float getYRotation() {
    return inputShape->rotation[1];
}

float getZRotation() {
    return 0;
}

float getXTranslation() {
    return 0;
}

float getYTranslation() {
    return 0;
}

float getZTranslation() {
    return 0;
}

float getXSheer() {
    return 0;
}

float getYSheer() {
    return 0;
}

float getZSheer() {
    return 0;
}

// ~~~~~~~~~~~~~~~~~ Setters ~~~~~~~~~~~~~~~~~~~ //
void setPoint(int index, struct point* newPoint) {
    // if the new point is null, don't set
    if (newPoint == NULL) {
        return;
    }

    // Otherwise if index is greater then 0 and is less then the number of points we have
    if ((index >= 0) && (index < inputShape->numOfPoints)) {
        // set the point at the index to the new point.
        inputShape->points[index] = newPoint;
    }
}

// ~~~~~~~~~~~~~~~~~ GROUP Setters Go HERE ~~~~~~~~~~~~~~~~~~~ //
void setGlobalScale(float newGlobalScale) {
}

void setXScale(float newXScale) {
  inputShape -> scaling[0] = newXScale;
}

void setYScale(float newYScale) {
}

void setZScale(float newZScale) {
}

void setXRotation(float newTheta) {
}

void setYRotation(float angle) {
    inputShape->rotation[1] = angle;
}

void setZRotation(float newTheta) {
}

void setXTranslation(float newXTranslation) {
}

void setYTranslation(float newYTranslation) {
}

void setZTranslation(float newZTranslation) {
}

void setXShear(float newXShear) {
}

void setYShear(float newYShear) {
}

void setZShear(float newZShear) {
}

void multiplyMatrix(struct point* currPoint, float matrix[4][4]) {
    // Error checking for NULL paramaters
    if (currPoint == NULL) {
        return;
    }

    struct point temp;

    // updating the points values
    for (int i = 0; i < 4; i++) {
        temp.element[i] = 0;
        for (int j = 0; j < 4; j++) {
            temp.element[i] += currPoint->element[j] * matrix[j][i];
        }
    }

    // storing new values into actual point
    for (int i = 0; i < 4; i++) {
        currPoint->element[i] = temp.element[i];
    }
}

//Reset transformation matrix to the identity matrix
void resetMatrix(){
  for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
          if (i == j){
              transformationMatrix[i][j] = 1;
          }
          else{
              transformationMatrix[i][j] = 0;
          }
      }
  }
}

void runAllTests() {
    int i;
    inputShape = malloc(sizeof(struct shape));

    inputShape->numOfPoints = 5;

    // SET YOUR VALUES HERE
    setYRotation(0);

    // Instantiation of the shape structure
    inputShape->points = malloc(sizeof(struct point*) * 5);

    for (i = 0; i < 5; i++) {
        struct point* temp = malloc(sizeof(struct point));
        for (int j = 0; j < 3; j++) {
            temp->element[j] = j + i;
        }
        temp->element[3] = 1;
        inputShape->points[i] = temp;
    }

    // TESTS GO HERE
    runGroup7Tests();  // Group 7 tests

    runScalingInXTests(); // Group 3 tests

    zPlaneReflectionTests(); // Group 12 tests

    // free
    for (i = 0; i < 5; i++) {
        free(inputShape->points[i]);
    }
    free(inputShape->points);

    free(inputShape);
}
