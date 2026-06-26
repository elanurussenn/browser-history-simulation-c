# 🌐 C Dili ile İki Yönlü Bağlı Liste Tabanlı Tarayıcı Geçmişi Simülasyonu

Bu proje; C programlama dili kullanılarak, modern web tarayıcılarının (Google Chrome, Mozilla Firefox vb.) sayfa geçmişi (Browser History) ile "Geri" ve "İleri" buton mekanizmalarını doğrusal olarak nasıl yönettiğini simüle eden **İki Yönlü Bağlı Liste (Doubly Linked List)** destekli bir **Yığın (Stack)** uygulamasıdır.

---

##  Algoritma ve Veri Yapısı Mimarisi

Yazılım mimarisinde, tarayıcı geçmişini sadece tek yönlü bağlı liste ile tutmak "Geri" gitmeyi sağlasa da, tekrar "İleri" gitmeyi imkansız hale getirir. Bu projede problem, düğümlerin hem bir sonraki sayfayı hem de bir önceki sayfayı adreslemesi sağlanarak çözülmüştür:

* **`struct Node`**: Her bir düğüm, ziyaret edilen web sitesinin adını (`data`), bir sonraki sayfayı işaret eden `next` pointer'ını ve bir önceki sayfayı işaret eden `prev` pointer'ını barındırır.
* **`struct Stack`**: Geçmiş yığınının en tepesindeki (aktif olarak bulunulan) web sitesini `top` işaretçisi ile dinamik olarak takip eder.

---

##  Fonksiyonel Özellikler ve Modüller

Sistem, konsol arayüzü (CLI) üzerinden kullanıcıya şu tarayıcı işlevlerini sunar:

1. **Yeni Sayfa Girişi (`push_fonk`):** Kullanıcıdan bir web sitesi URL'si alır, hafızada dinamik olarak yer ayırır (`malloc`) ve bu sayfayı yığının tepesine ekler. Mevcut sayfa ile yeni sayfa arasındaki `next` ve `prev` bağlarını kurarak geçmiş zincirini günceller.
2. **Geri Butonu Mekanizması (`gerifonks`):** Kullanıcının geçmişte bir adım geriye gitmesini sağlar. Yığının tepesindeki işaretçiyi `next` pointer'ı yönünde kaydırarak bir önceki sayfayı aktif hale getirir.
3. **İleri Butonu Mekanizması (`ilerifonks`):** Geri gelinen sayfalarda tekrar ileri gidilebilmesini sağlar. Bellekte tutulan `prev` pointer'ını geriye doğru takip ederek kullanıcının en son ayrıldığı güncel web sitesine yaklaşmasını sağlar.
4. **Geçmişi Listeleme (`display`):** Bellekteki iki yönlü zinciri tarayarak ziyaret edilen tüm web sitelerini aktif sayfadan başlayarak sırayla terminale basar.

---

##  Derleme ve Çalıştırma Talimatı

Proje tek bir kaynak kod dosyasından oluştuğu için herhangi bir harici kütüphaneye veya veri dosyasına ihtiyaç duymaz.

1. Bu depoyu bilgisayarınıza indirin veya klonlayın.
2. Terminal veya Komut İstemi'ni (CMD) açarak `main.c` dosyasının bulunduğu dizine gidin.
3. GCC derleyicisi yardımıyla kodu derleyin:
   ```bash
   gcc main.c -o browser_simulator
