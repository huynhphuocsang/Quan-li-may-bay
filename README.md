
# Tham khảo thêm 

Đồ án Quản lí thư viện-Trần Quang Vinh ft Đỗ Huỳnh Hồng Phúc: https://github.com/VinhVIP/Quan_Ly_Thu_Vien/

Đồ án Đồ thị: Nguyễn Trung Hiếu ft Nguyễn Văn Long : https://github.com/monarchzz/CTDL_Graph





# Đồ án QUẢN LÍ MÁY BAY-PTITHCM-2020-KHÓA D18


Đồ án QUẢN LÍ MÁY BAY-thầy Lưu Nguyễn Kỳ Thư_Học viện Công nghệ Bưu Chính Viễn Thông

-Tác giả: Huỳnh Phước Sang-Nguyễn Tá Huy khóa D18CQCN.

Kết quả: cả hai bạn đều qua môn và điểm khá êm :))).

Lưu ý: 

        +Phần giao diện lúc Đặt vé, theo ý thầy nhận xét các bạn nên chỉnh lại in ra số ghế hành khách đã đặt, chưa đặt để có cái nhìn trực quan hơn khi Đặt vé
	như thế sẽ có được UI tốt hơn chúng mình.

        +Về chức năng, thì theo thầy test HOÀN TOÀN không có bug hihi :)), nhưng mình biết có một con bug đó khi chúng ta nhập cho 1 máy bay thực
      hiện 2 chuyến bay: 1 chuyến thực hiện vào ngày 29/2 và 1 chuyến thực hiện ngày 1/3 vào năm nhuận, nếu nhập thời gian thực hiện 2 chuyến bay đó
      dưới 2 tiếng thì chương trình vẫn nhận===>sai, nhưng đây là lỗi nhỏ thôi, nên mong các bạn khi tham khảo có thể thêm vào hộ chúng mình nha! 
      Đồng thời sẵn tiện test thử xem chương trình này còn bug chỗ nào không nhé :)))!
      
       +Trong chương trình, chúng mình có thêm một vài thông số, như so_luot_thuc_hien,active,... thời gian thực hiện hai chuyến bay của một máy bay 
      cách nhau từ 2 tiếng trở lên, thời gian để một hành khách đặt vé trên hai chuyến bay khác nhau phải cách nhau hơn 30 phút. Những thông số trên do 
      chúng mình tự quy định, các bạn có thể chỉnh lại tùy ý mình nhé, miễn sao thấy hợp lí là được!
      
      
P/s: Chúc các bạn ôn bài thật kĩ và có nhân phẩm tốt để qua môn và đạt kết quả cao nhé!


============================================================================================================================================================================

Đề bài:

Quản lý các chuyến bay nội địa thuộc 1 hăng hàng không: Ta có các chức năng thuộc danh sách sau: 

- Máy bay : mảng con trỏ có tối đa 300 máy bay. Mỗi máy bay có các thông tin (Số hiệu MB (C15), loại máy bay (C40), số chỗ) ;  Mỗi máy bay có 1 số hiệu duy nhất; số chỗ >=20
- Chuyến bay : danh sách liên kết đơn ( Mã CB (C15),  Ngày giờ khởi hành, sân bay đến , trạng thái, Số hiệu MB, danh sách vé). Mỗi chuyến bay có 1 mã duy nhất; trạng thái chuyến bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé,3: hoàn tất ; danh sách vé cho biết thông tin vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó. Mỗi vé có  số vé  là số thứ tự trên chuyến từ số 1 đến số chỗ . Danh sách vé được cấp phát bộ nhớ tự động dựa vào số chỗ của máy bay thực hiện chuyến bay.
- Hành khách: cây nhị phân tìm kiếm cân bằng(Số CMND , Ho, Ten,  Phai)
Chương trình có các chức năng sau: 
a/ Cập nhập danh sách các máy bay (thêm / xóa / hiệu chỉnh)
b/ Cập nhật chuyến bay: cho phép lập chuyến bay mới, hiệu chỉnh ngày giờ khởi hành của chuyến bay , hủy chuyến.
c/Đặt vé: cho phép đặt vé trên 1 chuyến bay; nếu thông tin hành khách chưa có thì tự động cập nhật vào danh sách hành khách, nếu có rồi thì in ra màn hình để kiểm tra. Mỗi vé đều phải ghi nhận số CMND của hành khách; nếu hành khách chưa có số CMND thì yêu cầu nhập thông tin hành khách trước. Trên 1 chuyến bay, mỗi hành khách chỉ được mua 1 vé.
d/ Hủy vé: cho phép hủy vé đã đặt của hành khách.
e/ In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay. Kết xuất:
DANH SÁCH HÀNH KHÁCH THUỘC CHUYẾN BAY ######
Ngày giờ khởi hành: dd/mm/yyyy hh:mm.  Nơi đến : xxxxxxxxxxx

	STT	SỐ VÉ		SỐ CMND	HỌ TÊN	PHÁI
f/ In danh sách các chuyến bay khởi hành trong  ngày dd/mm/yyyy đến nơi XXXX   (cho biết cụ thể số lượng các vé còn trống và giờ khởi hành)
g/ In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X. 
h/ Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự  số lượt thực hiện giảm dần. Kết xuất:
	Số hiệu máy bay		Số lượt thực hiện chuyến bay

Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập liệu làm dữ liệu bị sai.

# Quan-li-may-bay
