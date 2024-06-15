#include <iostream>
#include <fstream>
#include <openssl/sha.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void computeSHA256(const std::string& data, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.length());
    SHA256_Final(hash, &sha256);
}

int main() {
    std::string imagePath = "C:\proga\laba-8\8-3\image.jpg";
    cv::Mat image = cv::imread(imagePath);
    
    if (image.empty()) {
        std::cerr << "Error loading image" << std::endl;
        return 1;
    }
    
    std::vector<uchar> imageData;
    cv::imencode(".jpg", image, imageData);
    std::string imageDataStr(imageData.begin(), imageData.end()); 
    unsigned char prehash[SHA256_DIGEST_LENGTH];
    computeSHA256(imageDataStr, prehash);
    image.at<cv::Vec3b>(10, 10)[0] = 255;
    cv::imencode(".jpg", image, imageData);
    imageDataStr = std::string(imageData.begin(), imageData.end());
    unsigned char posthash[SHA256_DIGEST_LENGTH];
    computeSHA256(imageDataStr, posthash);
    bool hashesMatch = true;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        if (prehash[i] != posthash[i]) {
            hashesMatch = false;
            break;
        }
    }
    std::cout << "Prehash: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", prehash[i]);
    }
    std::cout << std::endl;
    std::cout << "Posthash: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", posthash[i]);
    }
    std::cout << std::endl;
    std::ofstream outFile("hash_comparison.txt");
    if (outFile.is_open()) {
        outFile << "Prehash: ";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            outFile << std::hex << static_cast<int>(prehash[i]);
        }
        outFile << std::endl;
        outFile << "Posthash: ";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            outFile << std::hex << static_cast<int>(posthash[i]);
        }
        outFile << std::endl;
        outFile << "Hashes match: " << (hashesMatch ? "true" : "false") << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error opening output file" << std::endl;
    }
    return 0;
}