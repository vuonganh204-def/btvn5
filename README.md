# 🔐 RC4 Stream Cipher Project

## 📖 Giới thiệu

Đây là project *mã hóa và giải mã chuỗi thông tin sử dụng thuật toán RC4*, được lập trình bằng ngôn ngữ *C*.  
Chương trình được tách thành nhiều file header và source riêng biệt để thể hiện rõ *cấu trúc và hướng đi của thuật toán*, bao gồm cả *mã hóa* và *giải mã*.

Yêu cầu bài tập:  
- Mã hóa chuỗi “Hanoi University of Science and Technology” bằng RC4  
- Thuật toán được chia thành nhiều file header (`.h`)  
- Mã hóa và giải mã là **2 project độc lập**  
- Hàm `main` chỉ chứa **khai báo và gọi hàm** từ header  
- Commit code vào GitHub, tạo repo **public**, gắn link repo vào bài nộp  
- File `README.md` hướng dẫn **chạy chương trình** và cung cấp **bộ test vector**


---

##  Hướng đi của chương trình

1. *Chức năng chính:*
   - Mã hóa và giải mã chuỗi bằng thuật toán *RC4*
   - Cho phép chạy *test vector tự động* từ file Test_vector.txt
   - Cho phép *nhập thủ công* plaintext và key để tự kiểm thử

2. *Luồng hoạt động:*
   - Người dùng chọn chế độ từ menu:
     
     1. Chay Test Vector
     2. Nhap thu cong (User)
     3. Exit
     
   - Khi chọn *Test Vector*, chương trình đọc dữ liệu từ file và kiểm thử tự động.
   - Khi chọn *User*, người dùng nhập:
     - Key (dạng text)
     - Plaintext hoặc Ciphertext (dạng hex)
   - RC4 tiến hành mã hóa/giải mã và in kết quả ra màn hình.

3. *Nguyên lý thuật toán:*
   - **rc4_setup()**: Khởi tạo mảng hoán vị S[256] dựa trên khóa.  
   - **rc4_stream()**: Sinh keystream, XOR với dữ liệu để mã hóa/giải mã.  
   - Do RC4 là thuật toán đối xứng, cùng một hàm có thể dùng cho cả hai quá trình.

---
