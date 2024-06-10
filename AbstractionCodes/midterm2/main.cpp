#include <iostream>
#include <string>
#include "simpio.h"
#include "foreach.h"
#include "console.h"
#include <time.h>
#include "CircularQueue.hpp"
#include "ListSum.hpp"
#include "random.h"

using namespace std;

void printTestResults(bool passed, int testNum, int & passedCounter) {
    if (passed) {
        cout << "test " << testNum << " passed" << endl;
        passedCounter++;
    } else {
        cout << "test " << testNum << " failed" << endl;
    }
}

const int circularQueueTestsNum = 15;

bool runCircularQueueSingleTest(int testNum) {
    CircularQueue cq(1);
    bool passed = false;
    bool added = false;
    int val;
    switch (testNum) {
        case 1:
            cq = CircularQueue(2);
            passed = cq.IsEmpty() && !cq.IsFull();
            added = cq.Enqueue(1);
            passed = passed && added && !cq.IsEmpty() && !cq.IsFull();
            added = cq.Enqueue(2);
            passed = passed && added && !cq.IsEmpty() && cq.IsFull();
            added = cq.Enqueue(3);
            passed = passed && !added && !cq.IsEmpty() && cq.IsFull();
            break;
        case 2:
            cq = CircularQueue(2);
            added = cq.Enqueue(1);
            added = cq.Enqueue(2);
            val = cq.Dequeue();
            passed = val == 1 && !cq.IsEmpty() && !cq.IsFull();
            val = cq.Dequeue();
            passed = passed && val == 2 && cq.IsEmpty() && !cq.IsFull();
            break;
        case 3:
            cq = CircularQueue(2);
            added = cq.Enqueue(1);
            added = cq.Enqueue(2);
            val = cq.Dequeue();
            added = cq.Enqueue(3);
            passed = added && !cq.IsEmpty() && cq.IsFull();
            val = cq.Dequeue();
            passed = passed && val == 2 && !cq.IsEmpty() && !cq.IsFull();
            val = cq.Dequeue();
            passed = passed && val == 3 && cq.IsEmpty() && !cq.IsFull();
            break;
        case 4:
            cq = CircularQueue(2);
            added = cq.Enqueue(1);
            added = cq.Enqueue(2);
            val = cq.Dequeue();
            val = cq.Dequeue();
            passed = cq.IsEmpty() && !cq.IsFull();
            added = cq.Enqueue(3);
            added = cq.Enqueue(4);
            passed = passed && added && !cq.IsEmpty() && cq.IsFull();
            val = cq.Dequeue();
            passed = passed && val == 3 && !cq.IsEmpty() && !cq.IsFull();
            val = cq.Dequeue();
            passed = passed && val == 4 && cq.IsEmpty() && !cq.IsFull();
            break;
        case 5:
            cq = CircularQueue(1);
            added = cq.Enqueue(1);
            added = cq.Enqueue(2);
            passed = !added && !cq.IsEmpty() && cq.IsFull();
            val = cq.Dequeue();
            passed = passed && val == 1 && cq.IsEmpty() && !cq.IsFull();
            added = cq.Enqueue(3);
            added = cq.Enqueue(4);
            passed = passed && !added && !cq.IsEmpty() && cq.IsFull();
            val = cq.Dequeue();
            passed = passed && val == 3 && cq.IsEmpty() && !cq.IsFull();
            break;
        case 6:
            cq = CircularQueue(3);
            added = cq.Enqueue(1);
            added = cq.Enqueue(2);
            passed = cq.Dequeue() == 1 && cq.Dequeue() == 2 && cq.IsEmpty();
            added = cq.Enqueue(3) && cq.Enqueue(4) && cq.Enqueue(5);
            passed = passed && added && !cq.IsEmpty() && cq.IsFull();
            added = cq.Enqueue(6);
            passed = passed && !added;
            passed = passed && cq.Dequeue() == 3 && cq.Dequeue() == 4 &&
                                cq.Dequeue() == 5 && cq.IsEmpty();
            break;
        case 7:
            cq = CircularQueue(3);
            passed = cq.IsEmpty();
            for (int i=0; i<10; i++) {
                added = cq.Enqueue(i);
                val = cq.Dequeue();
                passed = passed && added && val == i;
            }
            passed = passed && cq.IsEmpty();
            break;
        case 8:
            cq = CircularQueue(5);
            passed = cq.IsEmpty();
            for (int i=0; i<10; i++) {
                for (int j=0; j<8; j++) {
                    cq.Enqueue(i*j);
                }
                for (int j=0; j<5; j++) {
                    val = cq.Dequeue();
                    passed = passed && val == i*j;
                }
                passed = passed && cq.IsEmpty();
            }
            passed = passed && cq.IsEmpty();
            break;
        case 9:
            cq = CircularQueue(1);
            passed = cq.IsEmpty();
            for (int i=0; i<10; i++) {
                cq.Enqueue(i);
                added = cq.Enqueue(i+1);
                added = added || cq.Enqueue(i+2);
                passed = passed && !added;
                val = cq.Dequeue();
                passed = passed && cq.IsEmpty() && val == i;
            }
            passed = passed && cq.IsEmpty();
            break;
        case 10:
            cq = CircularQueue(7);
            passed = cq.IsEmpty();
            for (int i=0; i<5; i++) {
                for (int j=0; j<10; j++) {
                    cq.Enqueue(i*j);
                }
                for (int j=0; j<7; j++) {
                    val = cq.Dequeue();
                    passed = passed && val == i*j;
                }
                passed = passed && cq.IsEmpty();
            }
            passed = passed && cq.IsEmpty();
            break;
        case 11:
            cq = CircularQueue(50000);
            for (int i=0; i<100000; i++) {
                cq.Enqueue(i);
            }
            passed = cq.IsFull();
            for (int i=0; i<50000; i++) {
                val = cq.Dequeue();
                passed = passed && val == i;
            }
            passed = passed && cq.IsEmpty();
            break;
        case 12:
            cq = CircularQueue(100000);
            passed = cq.IsEmpty();
            for (int i=0; i<200000; i++) {
                added = cq.Enqueue(i);
                val = cq.Dequeue();
                passed = passed && added && val == i;
            }
            passed = passed && cq.IsEmpty();
            break;
        case 13:
            cq = CircularQueue(100000);
            passed = cq.IsEmpty();
            for (int i=0; i<20000; i++) {
                for (int j=0; j<10; j++) {
                    cq.Enqueue(i*j);
                }
                for (int j=0; j<10; j++) {
                    val = cq.Dequeue();
                    passed = passed && val == i*j;
                }
                passed = passed && cq.IsEmpty();
            }
            break;
        case 14:
            cq = CircularQueue(1000);
            passed = cq.IsEmpty();
            for (int i=0; i<100; i++) {
                for (int j=0; j<2000; j++) {
                    cq.Enqueue(i*j);
                }
                for (int j=0; j<1000; j++) {
                    val = cq.Dequeue();
                    passed = passed && val == i*j;
                }
                passed = passed && cq.IsEmpty();
            }
            break;
        case 15:
            cq = CircularQueue(100);
            passed = cq.IsEmpty();
            for (int i=0; i<1000; i++) {
                for (int j=0; j<200; j++) {
                    cq.Enqueue(i*j);
                }
                for (int j=0; j<100; j++) {
                    val = cq.Dequeue();
                    passed = passed && val == i*j;
                }
                passed = passed && cq.IsEmpty();
            }
            break;
    }

    return passed;
}

void runCircularQueueAllTests() {
    cout << "### Run CircularQueue tests ###" << endl;
    int passedNum = 0;
    int testNum = 1;

    for (; testNum<=circularQueueTestsNum; testNum++) {
        bool passed = runCircularQueueSingleTest(testNum);

        printTestResults(passed, testNum, passedNum);
    }

    cout << "###### passed " << passedNum << " tests ######" << endl;
}


digit * buildNumbList(string num) {
    digit * list = NULL;
    for (int i=num.length()-1; i>=0; i--) {
        digit * d = new digit;
        d->d = num[i] - '0';
        d->next = list;
        list = d;
    }
    return list;
}

bool isEqual(digit * num1, digit * num2) {
    while (num1 != NULL && num2 != NULL) {
        if (num1->d != num2->d)
            return false;
        num1 = num1->next;
        num2 = num2->next;
    }

    return num1 == num2;
}

const int sumTestNum = 20;
string tests[sumTestNum][3] = {
    {"1", "5", "6"},
    {"11", "9", "20"},
    {"57", "184", "241"},
    {"99999", "1", "100000"},
    {"1", "999999999", "1000000000"},
    {"23745276", "12374512772", "12398258048"},
    {"9034872384", "1238719237918273912739", "1238719237927308785123"},
    {"234234234234234623457645765324", "53432453464563523454535", "234234287666688088021169219859"},
    {"2", "53432453464563523454312323453899", "53432453464563523454312323453901"},
    {"22938742922342234347299023497996", "14", "22938742922342234347299023498010"},
    {"123456789123456789123456789123456789123456789", "876543210876543210876543210876543210876543211", "1000000000000000000000000000000000000000000000"},
    {"999999999999999999999999999999999999999999999999999999999999999999999999", "1", "1000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"2", "999999999999999999999999999999999999999999999999999999999999999999999999", "1000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"83170726453663295588400077865907207627040733774094", "522134431212312312349817490794017094124719741902749187091273471247140140164710247107401748140124014791839", "522134431212312312349817490794017094124719741902749187174444197700803435753110324973308955767164748565933"},
    {"999999999999999999999999999999999999999999999999999999999999999999999999", "999999999999999999999999999999999999999999999999999999999999999999999999", "1999999999999999999999999999999999999999999999999999999999999999999999998"},
    {"522134431212312312349817490794017094124719741902749187091273471247140140164710247107401748140124014791839", "8528161", "522134431212312312349817490794017094124719741902749187091273471247140140164710247107401748140124023320000"},
    {"99", "522134431212312312349817490794017094124719741902749187091273471247140140164710247107401748140124014791740", "522134431212312312349817490794017094124719741902749187091273471247140140164710247107401748140124014791839"},
    {"83170726453663295588400077865907207627040733774094", "543389219096857082582990474724508625339998201083802565187777", "543389219180027809036653770312908703205905408710843298961871"},
    {"2122346046026026870118467274332986069682068574104645075051474474311596727825316633724945120116780003", "1666091723130359171516735616181797648284335334633", "2122346046026026870118467274332986069682068574104646741143197604670768244560932815522593404452114636"},
    {"522134431212312312349817490794017094124719741902749187091273471247140140104710247107401740140124014701740", "120938102809759647196172419041294710927951974017401740174174017204140104972109471209470147147017240174017", "643072534022071959545989909835311805052671715920150927265447488451280245076819718316871887287141254875757"},
};


bool runSumSingleTest(int testNum) {
    digit * num1 = buildNumbList(tests[testNum-1][0]);
    digit * num2 = buildNumbList(tests[testNum-1][1]);
    digit * answ = buildNumbList(tests[testNum-1][2]);
    
    digit * res = sum(num1, num2);
    return isEqual(res, answ);
}

void runSumAllTests() {
    cout << "### Run Sum tests ###" << endl;
    int passedNum = 0;
    int testNum = 1;

    for (; testNum<=sumTestNum; testNum++) {
        bool res = runSumSingleTest(testNum);
        printTestResults(res, testNum, passedNum);
    }

    cout << "###### passed " << passedNum << " tests ######" << endl;
}

int main() {
    runCircularQueueAllTests();
    runSumAllTests();
    cout << "end" << endl;
    return 0;
}
