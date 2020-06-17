#include <iostream>
#include <openssl/rc4.h>
#include <openssl/des.h>
#include <openssl/sha.h>

using namespace std;

// ================ RC4 Start ================================

// 该函数实现RC4加密算法功能
//  参数:
//      data - 输入的明文字符串
//      secret_key - 密钥
//  返回值:
//      string类型, 返回加密的结果。如果输入数据异常，则返回空字符串并退出
string rc4_encrypt(string data, string secret_key) {
    RC4_KEY set1;
    int length = strlen(secret_key.c_str());
    RC4_set_key(&set1,length,(const unsigned char *)secret_key.c_str());
    int len = strlen(data.c_str());
    unsigned char *outdata;
    outdata = (unsigned char *)malloc(size(unsigned char)*(len));
    memset(outdata,0,len);
    RC4(set1, (unsigned long)len, (const unsigned char *)data.c_str(), outdata);
    return (char *)outdata;
}

// 该函数实现RC4解密算法功能
//  参数:
//      data - 输入的密文字符串
//      secret_key - 密钥
//  返回值:
//      string类型, 返回解密的结果。如果输入数据异常，则返回空字符串并退出
string rc4_decrypt(string data, string secret_key) {
    int len = strlen(data.c_str());
    unsigned char *plain;//分配明文空间
    plain=(unsigned char *)malloc(sizeof(unsigned char)*(len));
    memset(plain,0,len);//初始化为0
    RC4_KEY set1;
    int length = strlen(secret_key.c_str());
    RC4_set_key(&set1,length,(const unsigned char *)secret_key.c_str());
    RC4(&set1,strlen(data.c_str()),data.c_str(),plain);//解密密文
    return (char *)plain;
}

// ================ RC4   End ================================


// ================ DES Start ================================

// 请使用该函数将string类型转换为DES_cblock类型。（请勿更改此函数）
// - 该函数仅用于转换明文和密文内容，请不要把用此函数转换secret_key。
// - secret_key请使用`DES_string_to_key()`函数转换。
void convert_string_to_des_block(string str, DES_cblock &output);

// 该函数实现DES-ECB加密算法功能
//  参数:
//      plain - 输入的明文字符串
//      secret_key - 密钥
//  返回值:
//      string类型, 返回加密的结果
//  其他说明:
//      - 请使用`convert_string_to_des_block()`函数将string类型转换为DES_cblock类型。
//        若自行转换，可能导致测试无法通过
//      - secret_key使用前请用`DES_string_to_key()`设置key；
string des_encrypt(string plain, string secret_key) {
    DES_cblock key; // DES_cblock结构: typedef unsigned char des_cblock[8];
    DES_string_to_key(secret_key,&key);
    DES_random_key(&key); // 随机产生密钥
    DES_key_schedule keys;
    DES_set_key_checked(&secret_keytext, &keys);//随机子密钥
    DES_cblock plaintext, ciphertext;
    convert_string_to_des_block(plain,&plaintext);
    DES_ecb_encrypt(&plaintext, &ciphertext, &keys, DES_ENCRYPT);
    return (char*)ciphertext;
}

// 该函数实现DES-ECB解密算法功能
//  参数:
//      cipher - 输入的密文字符串
//      secret_key - 密钥
//  返回值:
//      string类型, 返回解密的结果
//  其他说明:
//      - 请使用`convert_string_to_des_block()`函数将string类型转换为DES_cblock类型。
//        若自行转换，可能导致测试无法通过
//      - secret_key使用前请用`DES_string_to_key()`设置key
string des_decrypt(string cipher, string secret_key) {
    DES_cblock key; // DES_cblock结构: typedef unsigned char des_cblock[8];
    DES_string_to_key(secret_key,&key);
    DES_random_key(&key); // 随机产生密钥
    DES_key_schedule keys;
    DES_set_key_checked(&secret_keytext, &keys);//随机子密钥
    DES_cblock plaintext, ciphertext;
    convert_string_to_des_block(cipher,&ciphertext);
    DES_ecb_encrypt(&plaintext, &ciphertext, &keys, DES_DECRYPT);
    return (char*)plaintext;
}

// ================ DES   End ================================

// ================ SHA1 Start ===============================

// 该函数实现SHA1 hash算法功能
//  参数:
//      msg - 输入的字符串
//  返回值:
//      string类型, 返回sha1消息摘要结果
string sha1_digest(string msg) {
    /* Case：消息能够在内存中存放 */
    /* 定义msg为消息，msg_len为消息长度，hash为至少20字节缓冲池 */
    char hash[40];
    int msg_len = strlen(msg.c_str());
    SHA(msg, msg_len, hash);
    // /* Case：消息难以在内存中存放 */
    // /* 定义chunk为消息的每个切块，chunk_len为chunk长度 */
    // SHA_CTX ctx;
    // SHA1_Init(&ctx);
    // SHA1_Update(&ctx, chunk, chunk_len);
    // SHA1_Final(hash, &ctx);
    return hash;
}
// ================ SHA1   End ===============================

// ================ Helper Start =============================
// Helper 说明：
//     1. 你的测试已经全部完成了，不用再往下看了。
//     2. 请勿修改以下内容。其他功能函数。尝试修改可能导致单元测试无法通过

void convert_string_to_des_block(string str, DES_cblock &output) {
    for(int i = 0; i < 8; ++i) {
        output[i] = str[i];
    }
}
// ================ Helper End ================================
