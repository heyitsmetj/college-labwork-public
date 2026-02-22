package com.example.te2202a4seta1;

import android.os.Bundle;
import android.widget.ListView;
import androidx.appcompat.app.AppCompatActivity;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    ListView listView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = findViewById(R.id.listView);

        ArrayList<Contact> contacts = new ArrayList<>();

        contacts.add(new Contact(R.mipmap.ic_launcher, "Rahul", "9876543210", "rahul@gmail.com"));
        contacts.add(new Contact(R.mipmap.ic_launcher, "Priya", "9123456780", "priya@gmail.com"));
        contacts.add(new Contact(R.mipmap.ic_launcher, "Amit", "9988776655", "amit@gmail.com"));

        ContactAdapter adapter = new ContactAdapter(this, contacts);
        listView.setAdapter(adapter);
    }
}
