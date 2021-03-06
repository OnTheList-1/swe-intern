#include <iostream>
#include <map>

#include "chapter5.h"
#include "chapter5_1.h"


template <typename T> //bai 301
bool isSubset(const T* array1, const T& size1, const T* array2, const T& size2)
{
    if (size1 > size2)
    {
        return false;
    }

    bool isAnElement = false;

    for (int i = 0; i < size1; ++i)
    {
        for (int j = 0; j < size2; ++j)
        {
            if (array1[j] != array2[i])
                isAnElement = true;
        }
        if (isAnElement)
            return false;
    }
    return true;
}

template <typename T> //bai 302
int countAinB(const T* array1, const T& size1, const T* array2, const T& size2)
{
    int count = 0;

    for (int i = 0; i < size1; ++i)
    {
        if (array1[0] == array2[i] && size2 - i >= size1)
        {
            int startPosition = i;
            bool checkSubset = true;
            for (int j = 0; j < size1; j++)
            {
                if (array1[j] != array2[startPosition])
                {
                    checkSubset = 0;
                    break;
                }
                ++startPosition;
            }
            if (checkSubset)
                ++count;

        }
    }
    return count;
}

int main() {
    std::cout << "---------- Chapter 5 ----------" << "\n\n";

    std::vector<int> intType;
    std::vector<float> floatType;
    std::cout << "Enter a vector containing int datatype: \n\n";
    insertVector(intType);
    std::cout << "\nEnter a vector containing float datatype: \n\n";
    insertVector(floatType);

    std::cout << "\nBai 115: \n"; //bai 115
    std::cout << "Answer: " << avgGrade() << "\n";
    std::cout << "\n\nBai 122:\n"; //bai 122
    std::cout << "Answer: " << maxNum(floatType);
    std::cout << "\n\nBai 123:\n"; //bai 123
    std::cout << "Answer: " << minNumPosition(floatType) << "\n";
    std::cout << "\nBai127: Sort\n"; //bai 127
    std::vector<float> copy = floatType;
    sortArr(copy);
    for (auto i : copy)
        std::cout << i << " ";
    std::cout << "\n\nBai 133\n"; //bai 133
    listPosNegativeNumber(floatType);
    std::cout << "\nBai 136: Find the position of the last positive number in an array. \n"; //bai136
    std::cout << "Last Position is " << findLastEvenNumber(intType) << "\n";
    std::cout << "\nBai 137:";
    std::cout << "\nLast Position is " << lastPerfectNumberPos(intType) << "\n"; //bai137
    std::cout << "\nBai 141: Find the position of the smallest positive number\n"; //bai 141
    std::cout << "Smallest positive number's position is: " << smallestPositiveNumberPos(floatType) << "\n";
    std::cout << "\nBai 150: Find the biggest negative number"; //bai 150
    std::cout << "\nBiggest negative number is " << biggestNegativeNumber(floatType) << "\n";
    std::cout << "\nBai 156: Find the closest value to X\n"; //bai 156
    std::cout << "Answer: " << closestMinX(floatType);
    std::cout << "\n\nBai 157: Print [a,b] in the array.\n"; //bai 157
    printRange(floatType); //print [3.5, 4] in the array
    std::cout << "\n\nBai 158: Find if the array contain X where X is the product of [x - 1] && [x + 1] \n"; //bai 162
    std::cout << "Answer: " << productNearby(intType) << "\n";
    std::cout << "\nBai 166: Find if the array contain elements whom value is 2^k\n"; //bai 166
    std::cout << "Answer: " << baseTwoInArray(intType) << "\n";
    std::cout << "\nBai 169: Find the biggest even number that is less than all of the odd numbers.\n"; //bai 169
    std::cout << "Answer: " << biggestEvenLessThanOdd(intType) << "\n";
    std::cout << "\nBai 173: \n"; // bai 173
    std::cout << "Answer: " << findLeastFrequency(intType) << "\n";
    std::cout << "\nBai 174: List all pairs in the array where a < b\n"; //bai 174
    listAllPairs(floatType);
    std::cout << "\n\nBai 175: Find two elements most closest in value.\n";
    listPairClosest(floatType);
    std::cout << "\nBai 180: list all numbers n in the array where: n < abs(-1); n > abs(+1)\n";
    bai180(floatType);
    std::cout << "\n\nBai 182: List all numbers that has at least one element next to it where the sign is different.\n";
    listDiffSign(floatType);
    std::cout << "\nBai 190: List all elements in the array where each of its digits are odd numbers.\n";
    listOddDigit(intType);
    std::cout << "\n\nBai 192: List all elements in the array where the first digit is an even number.\n";
    firstElementEven(intType);
    std::cout << "\n\nBai 195: List all 3 values in an array where a = b + c and a, b, c are distinct.\n";
    bai195(floatType);
    std::cout << "\n\nBai 202: Sum all numbers where their first digit is odd.\n";
    std::cout << "Answer: " << sumFirstDigitOdd(intType) << "\n";
    std::cout << "\nBai 207: Sum of all the extreme elements.\n";
    std::cout << "Answer: " << sumExtremeElement(floatType) << "\n";
    std::cout << "\nBai 215: Find average distance between all elements in the array.\n";
    std::cout << "Answer: " << findAvgDistanceBetweenElements(floatType);
    std::cout << "\nBai 221: Count the numbers of odd and even. [-1 even > odd; 0 odd == even; odd > even]\n";
    std::cout << "Answer: " << compareCountOddEven(intType) << "\n";
    std::cout << "\nBai 226: Count numbers of elements in which the one next to it is also even.\n";
    std::cout << "Answer: " << countNextToEven(intType) << "\n";
    std::cout << "\nBai 230: Count distinct elements and it's occurrences.";
    countDistinctElement(floatType);
    std::cout << "\nBai 231: List all unique elements in the array.\n";
    listDistinctElements(floatType);

    std::cout << "\nBai 236: Count the number of times A appears in B.\n";
    std::vector<float> floatTypeExample{ 1, 2 };
    std::cout << "Answer: " << countAinB(floatTypeExample, floatType) << std::endl;
    std::cout << "\nBai 238: List the mode in the array.\n";
    listModeInArray(intType);
    std::cout << "\n\nBai 241: Consecutive Zeros\n";
    std::cout << "Answer: " << isConsecutiveZeros(intType) << "\n";
    std::cout << "\nBai 246: Symetrical Array\n";
    std::cout << "Answer : " << isSymetricalArray(floatType) << "\n";
    std::cout << "\nBai 249: Descending Array\n";
    std::cout << "Answer: " << isDescendingArray(floatType) << "\n";
    std::cout << "\nBai 256: Sort Array Descending\n";
    std::vector<float> copy256(floatType.begin(), floatType.end());
    sortArrayDescending(copy256);
    std::cout << "\n\nBai257: Sort Array Odd elements ascending.\n";
    std::vector<float> copy257(floatType.begin(), floatType.end());
    sortArrayOddAscending(copy257);
    std::cout << "\nBai261: Sort array in ascending positive numbers.\n";
    std::vector<float> copy261(floatType.begin(), floatType.end());
    sortArrayPositiveAscending(copy261);
    std::cout << "\nBai 263: Sort array where positive ascends and negative descends\n";
    std::vector<float> copy263(floatType.begin(), floatType.end());
    sortArrayBai263(copy263);
    std::cout << "\nBai 266: Insert element into an array.";
    int copy266[100] = { 1,2,3,4,5 };
    insertAtK(copy266, 5, 2);
    std::cout << "\n Bai 267: Sort while insert\n";
    float copy267[100];
    sortWhileInsert(copy267, 5);
    std::cout << "\nBai 271: Delete all element K in the array\n";
    float copy271[100] = { 1, 1, 1, 1, 2, 3, 4, 5, 1, 3, 7 };
    int sz271 = 11;
    deleteAllK(copy271, sz271, 1);
    std::cout << "\nBai 274: Delete all even element K in the array\n";
    int copy274[100] = { 7, 8, 7, 1, 2, 3, 4, 5, 6 };
    int sz274 = 9;
    deleteEvenNumbers(copy274, sz274);
    std::cout << "\nBai 279: Delete Duplicates\n";
    int copy279[100] = { 3, 1, 1, 2, 0, 8, 3, 7, 2 };
    int size279 = 9;
    deleteDuplicates(copy279, size279);
    std::cout << "\nBai 281: Sort array where even goes front, 0 mid and odd back\n";
    int copy281[100] = { 4, 1, 8, 0, -3, 2, -1, 0, 1 };
    int size281 = 8;
    sortBai281(copy281, size281);
    std::cout << "\nBai 283: Reverse Array\n";
    int copy283[100] = { 1, 2, 3, 4, 5 };
    int size283 = 4;
    reverseArray(copy283, size283);
    std::cout << "\nBai 284: Reverse Even number's position.\n";
    int copy284[100] = { 1, 5, 3, 2, 1, 8, 7 };
    int size284 = 7;
    reverseEvenPosition(copy284, size284);
    std::cout << "\nBai 286: Rotote Array anti clockwise\n";
    int copy286[100] = { 1, 3, 2, 6, 5 };
    int size286 = 5;
    rotateArray(copy286, size286);
    std::cout << "\nBai 287: Rotate Array K Times to the right\n";
    int copy287[100] = { 1, 3, 2, 6, 7, 8, 3, 0 };
    int size287 = 8;
    rotateArrayKTimes(copy287, size287, 3);
    std::cout << "\nBai 289: Print odd and even separated by a line break.\n";
    printBai289(copy287, size287);
    std::cout << "\nBai 292: Promote array to int.\n";
    float bai292[100] = { 1.2f, 3, 4.5f, 5.4f, 2, 5.1f, 0 };
    int sizebai292 = 7;
    arrayToInt(bai292, sizebai292);
    std::cout << "\nBai 293: List all subset in an array.\n";
    int bai293[100] = { 1, 2, 3 };
    int size293 = 3;
    listArraySubset(bai293, size293);
    std::cout << "\nBai 295: List ascending subset in an array.\n";
    int bai295[100] = { 1, 2, 3, 1, 5, 2, 1, 5, 4, 5 };
    int size295 = 10;
    listSubsetAscending(bai295, size295);
    std::cout << "Bai 301: is A a subset of B.\n";
    int a[100] = { 1 };
    int b[100] = { 1, 2 , 3 ,4, 5 };
    std::cout << "Answer: " << isSubset(a, 2, b, 5) << "\n";
    std::cout << "\nBai 302: count A in B.\n";
    std::cout << countAinB(a, 1, b, 5);
    std::cout << "\nBai 304: Subset in A that sum up to M.\n";
    int bai304[100] = { 3, 6, 2, 9, -1, 11, 33, 2, 5, 1, 4, 9 };
    subsetSumM(bai304, 11, 10);
    std::cout << "\nBai 305: Largest positve subset in A\n";
    positiveSubsetLargestSum(bai304, 11);
    std::cout << "\nBai 309: \n";
    float bai309s[100] = { 2, -1, 4, -7, 10, 5, -9, 5, 8, 12, -10 };
    createArrayBai309(bai309s, 11);


    return 0;
}