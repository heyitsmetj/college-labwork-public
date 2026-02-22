package com.example.te2202a4seta1;

public class Contact {

    int image;
    String name, phone, email;

    public Contact(int image, String name, String phone, String email) {
        this.image = image;
        this.name = name;
        this.phone = phone;
        this.email = email;
    }

    public int getImage() { return image; }
    public String getName() { return name; }
    public String getPhone() { return phone; }
    public String getEmail() { return email; }
}
