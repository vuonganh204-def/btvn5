#include "RC4.h"
#include "decrypt.h" 

#define MAX_LINE_LEN 512
#define MAX_KEY_LEN 256
#define DEFAULT_KEYSTREAM_LEN 256

void decrypt_rc4() {
    char input_buffer[MAX_LINE_LEN];
    uint8_t user_key[MAX_KEY_LEN];
    uint8_t ciphertext_bytes[MAX_LINE_LEN];
    uint8_t* keystream = NULL;
    uint8_t* plaintext = NULL;

    while (1) {
        printf("Nhap Key (dang text) hoac nhan Enter de thoat.\n");
        printf("Key: ");

        if (!fgets(input_buffer, sizeof(input_buffer), stdin)) break;
        input_buffer[strcspn(input_buffer, "\n")] = 0;

        //Lấy key
        int key_len = strlen(input_buffer);

        //Kiểm tra key rỗng để thoát
        if (key_len == 0) {
            printf("Thoat.\n");
            break; //Thoát nếu nhấn Enter
        }

        if (key_len > MAX_KEY_LEN) {
            printf("Key qua dai! Nhap lai key!\n");
            continue;
        }
        memcpy(user_key, input_buffer, key_len);

        //Lấy Ciphertext (dạng HEX)
        printf("Nhap Ciphertext (dang hex):\n");
        printf("Ciphertext: ");

        if (!fgets(input_buffer, sizeof(input_buffer), stdin)) break;
        input_buffer[strcspn(input_buffer, "\n")] = 0;

        if (strlen(input_buffer) == 0) {
            printf("Ciphertext khong duoc rong.\n");
            continue;
        }

        int ciphertext_len = parse_hex_string(input_buffer, ciphertext_bytes, MAX_LINE_LEN);
        if (ciphertext_len == 0) {
            printf("Chuoi hex khong hop le. Vui long chi nhap cac ky tu hex.\n");
            continue;
        }

        //RC4 và Keystream
        RC4 ctx;
        ctx.keylen = key_len;
        memcpy(ctx.key, user_key, key_len);
        rc4_setup(&ctx);

        keystream = (uint8_t*)malloc(DEFAULT_KEYSTREAM_LEN);
        if (!keystream) {
            printf("Phan bo bo nho that bai!\n");
            continue;
        }
        rc4_stream(&ctx, keystream, DEFAULT_KEYSTREAM_LEN);

        //Giải mã
        int decrypt_len = ciphertext_len;
        if (ciphertext_len > DEFAULT_KEYSTREAM_LEN) {
            decrypt_len = DEFAULT_KEYSTREAM_LEN;
            printf("Ciphertext dai hon keystream. Chi giai ma %d bytes dau tien.\n", decrypt_len);
        }

        plaintext = (uint8_t*)malloc(decrypt_len + 1);
        if (!plaintext) {
            printf("Phan bo bo nho that bai!\n");
            free(keystream);
            continue;
        }

        for (int i = 0; i < decrypt_len; i++) {
            plaintext[i] = ciphertext_bytes[i] ^ keystream[i];
        }
        plaintext[decrypt_len] = '\0';

        //In Plaintext
        printf("\n--- Plaintext (da giai ma) ---\n");
        printf("%s\n", (char*)plaintext);

        //Dọn dẹp
        free(keystream);
        free(plaintext);
    }
}