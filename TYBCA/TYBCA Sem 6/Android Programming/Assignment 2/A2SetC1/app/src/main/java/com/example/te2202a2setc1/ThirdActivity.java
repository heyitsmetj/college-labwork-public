package com.example.te2202a2setc1;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class ThirdActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);

        TextView t = findViewById(R.id.txtProfile);

        Intent i = getIntent();

        String data =
                "Name: " + i.getStringExtra("name") + "\n" +
                        "DOB: " + i.getStringExtra("dob") + "\n" +
                        "Gender: " + i.getStringExtra("gender") + "\n" +
                        "Address: " + i.getStringExtra("address") + "\n" +
                        "Contact: " + i.getStringExtra("contact");

        t.setText(data);
    }
}
