#include "../implementation/unit_7.cc"
#include "catch2/catch.hpp"

using namespace std;

// wrapper for convert string to hex
string string2hex(string str);

// wrapper for convert hex to string
string hex2string(string hex_str);

TEST_CASE("RC4", "[unit_7]") {
    SECTION("RC4: Encryption") {
        string result;
        result = rc4_encrypt("1234", "1234");
        REQUIRE(string2hex(result) == "347B429B");

        result = rc4_encrypt("test", "test");
        REQUIRE(string2hex(result) == "DAEA5465");

        result = rc4_encrypt("testtest", "secret");
        REQUIRE(string2hex(result) == "9953A168F6C1A5D2");

        result = rc4_encrypt("test", "secretsecret");
        REQUIRE(string2hex(result) == "9953A168");
    }

    SECTION("RC4: Decryption") {
        string result;

        result = rc4_decrypt(hex2string("DAEA5465"), "test");
        REQUIRE(result == "test");

        result = rc4_decrypt(hex2string("347B429B"), "1234");
        REQUIRE(result == "1234");
    }

    SECTION("RC4: Error handling") {
        string result;

        // encode
        result = rc4_encrypt("test", "");
        REQUIRE(string2hex(result) == "");

        result = rc4_encrypt("", "test");
        REQUIRE(string2hex(result) == "");

        result = rc4_encrypt("", "");
        REQUIRE(string2hex(result) == "");

        // decode
        result = rc4_decrypt("", "1234");
        REQUIRE(result == "");

        result = rc4_decrypt("test", "");
        REQUIRE(result == "");

        result = rc4_decrypt("", "");
        REQUIRE(result == "");
    }
}

TEST_CASE("DES", "[unit_7]") {
    SECTION("DES: Encryption") {
        string result;
        result = des_encrypt("12341234", "12341234");
        REQUIRE(string2hex(result) == "0D05989E6F2605FA");

        result = des_encrypt("testtest", "testtest");
        REQUIRE(string2hex(result) == "C5F46DCDF74A428A");

        result = des_encrypt("testtest", "test");
        REQUIRE(string2hex(result) == "2BC76F988013097E");
    }
    SECTION("DES: Decryption") {
        string result;

        result = des_decrypt(hex2string("0D05989E6F2605FA"), "12341234");
        REQUIRE(result == "12341234");

        result = des_decrypt(hex2string("C5F46DCDF74A428A"), "testtest");
        REQUIRE(result == "testtest");

        result = des_decrypt(hex2string("2BC76F988013097E"), "test");
        REQUIRE(result == "testtest");
    }
}

TEST_CASE("SHA1 Digest", "[unit_7]") {
    SECTION("Digest") {
        REQUIRE(string2hex(sha1_digest("")) == "DA39A3EE5E6B4B0D3255BFEF95601890AFD80709");

        REQUIRE(string2hex(sha1_digest("test")) == "A94A8FE5CCB19BA61C4C0873D391E987982FBBD3");

        REQUIRE(string2hex(sha1_digest("infosec")) == "2BC36D3DD474443B82C626272951824F18B0334E");

        REQUIRE(string2hex(sha1_digest("DA39A3EE5E6B4B0D3255BFEF95601890AFD80709")) == "4026E982E356B8AFF02CAA2601C6BCB17FB5C645");
    }
}

// code from: https://stackoverflow.com/a/35599923/8587335
// Convert string of chars to its representative string of hex numbers
void stream2hex(const std::string str, std::string &hexstr, bool capital = false) {
    hexstr.resize(str.size() * 2);
    const size_t a = capital ? 'A' - 1 : 'a' - 1;

    for (size_t i = 0, c = str[0] & 0xFF; i < hexstr.size(); c = str[i / 2] & 0xFF) {
        hexstr[i++] = c > 0x9F ? (c / 16 - 9) | a : c / 16 | '0';
        hexstr[i++] = (c & 0xF) > 9 ? (c % 16 - 9) | a : c % 16 | '0';
    }
}

// Convert string of hex numbers to its equivalent char-stream
void hex2stream(const std::string hexstr, std::string &str) {
    str.resize((hexstr.size() + 1) / 2);

    for (size_t i = 0, j = 0; i < str.size(); i++, j++) {
        str[i] = (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) << 4, j++;
        str[i] |= (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) & 0xF;
    }
}

// wrapper for convert string to hex
string string2hex(const string str) {
    string s;
    stream2hex(str, s, true);
    return s;
}

// wrapper for convert hex to string
string hex2string(const string hex_str) {
    string s;
    hex2stream(hex_str, s);
    return s;
}
