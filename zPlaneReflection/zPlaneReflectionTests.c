#include "zPlaneReflectionTests.h"


void zPlaneReflectionTests() {
  zPlaneReflectionTest1();
	zPlaneReflectionTest2();
	zPlaneReflectionTest3();
	zPlaneReflectionTest4();
	zPlaneReflectionTest5();
}
void zPlaneReflectionTest1() {
	struct point test2[inputShape->numOfPoints];
	for (int i = 0; i < inputShape->numOfPoints; i ++) {
		for (int j = 0; j < 4; j ++) {
			test2[i].element[j] = getPoint(i)->element[j];
		}
	}
	for (int i = 0; i < inputShape->numOfPoints; i ++) {
		test2[i].element[2] *= -1;
	}
    zPlaneReflection(); // multiply inputShape by our reflection matrix
    for (int i = 0; i < inputShape->numOfPoints; i ++) {
        if (getPoint(i)->element[2] != test2[i].element[2]) { // test if initialization passes
            printf("Failed clean test, point number %d did not reflect properly.\n",i);
        }
    } 
	//restore old values
	zPlaneReflection();

}
// Dirty test 1, points are uninitialized. Should generate error when accessing point for reflection calculations, our function should detect this, and print an error message.
void zPlaneReflectionTest2() {
	struct point ** temp3 = inputShape->points;
	inputShape->points = NULL;
  zPlaneReflection();
	if (inputShape->points != NULL) {
		printf("zPlaneReflection falied dirty test 1.\n");
	}
	//restore points
	inputShape->points = temp3;
}
// Dirty test 2, calling function after the global shape has been freed.
// This should cause a segmentation fault when trying to access the global shape for editing, but our function should catch that and print an error statement.
void zPlaneReflectionTest3() {
	//store old shape
	struct shape * temp;
	temp = inputShape;
	inputShape = NULL;
  zPlaneReflection();
	if (inputShape != NULL) {
		printf("zPlaneReflection failed dirty test 2.\n");
	}
	//restore old shape
	inputShape = temp;
}
// Dirty test 3, calling functiopoints which use numbers too large to be a float.
// Should produce a logical error and our function will catch that and state which point is invalid.
void zPlaneReflectionTest4(){
  float over = FLT_MAX * 10; // over the max number that can be represented in a float
  struct point * test = malloc(sizeof(struct point));
	struct point * temp[inputShape->numOfPoints];
	for (int i = 0; i < inputShape->numOfPoints; i ++) { // save point values
    temp[i] = getPoint(i);
  }
  for (int i = 0; i < 4; i ++) { // initialize
    test->element[i] = over;
  }
  for (int i = 0; i < inputShape->numOfPoints; i ++) {
    setPoint(i, test);
  }
  zPlaneReflection();
	for (int i = 0; i < inputShape->numOfPoints; i ++) {
		for (int j = 0; j < 4; j ++) {
			if (getPoint(i)->element[j] != test->element[j]) {
				printf("zPlaneReflection failed dirty test 3.\n");
				i = inputShape->numOfPoints + 1;
				break;
			}
		}
	}
	for (int i = 0; i < inputShape->numOfPoints; i ++) { // restore point values;
    setPoint(i, temp[i]);
  }
	free(test);
}
// Dirty test 4, calling function with points which use numbers too small to be a float.
// Should produce a logical error and our function will catch that and state which point is invalid.
void zPlaneReflectionTest5() {
  float under = FLT_MIN / 10;
 	struct point * test = malloc(sizeof(struct point));
	struct point  * temp[inputShape->numOfPoints];
	for (int i = 0; i < inputShape->numOfPoints; i ++) { // savepoint values
    temp[i] = getPoint(i);
  }
  for (int i = 0; i < 4; i ++) { // initialize
    test->element[i] = under;
  }
  for (int i = 0; i < inputShape->numOfPoints; i ++) {
    setPoint(i, test);
  }
  zPlaneReflection();
  for (int i = 0; i < inputShape->numOfPoints; i ++) {
		for (int j = 0; j < 4; j ++) {
			if (getPoint(i)->element[j] != test->element[j]) {
				printf("zPlaneReflection failed dirty test 4.\n");
				i = inputShape->numOfPoints + 1;
				break;
			}
		}
	}
	for (int i = 0; i < inputShape->numOfPoints; i ++) { //restore point values
    setPoint (i, temp[i]);
  }
	free(test);
}
