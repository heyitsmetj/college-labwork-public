package com.example.te2202a2setb2;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        TextView t = findViewById(R.id.txtResult);

        Intent i = getIntent();
        String data =
                "First Name: " + i.getStringExtra("fname") + "\n" +
                        "Middle Name: " + i.getStringExtra("mname") + "\n" +
                        "Last Name: " + i.getStringExtra("lname") + "\n" +
                        "DOB: " + i.getStringExtra("dob") + "\n" +
                        "Address: " + i.getStringExtra("addr") + "\n" +
                        "Email: " + i.getStringExtra("email");

        t.setText(data);
    }
}
