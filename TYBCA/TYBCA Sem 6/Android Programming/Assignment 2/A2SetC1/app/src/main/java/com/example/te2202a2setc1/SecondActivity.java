package com.example.te2202a2setc1;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        Button btn = findViewById(R.id.btnProfile);

        btn.setOnClickListener(v -> {
            Intent i = new Intent(SecondActivity.this, ThirdActivity.class);

            // Passing data using Intent
            i.putExtra("name", "Rovel Pinto");
            i.putExtra("dob", "29/05/1992");
            i.putExtra("gender", "Male");
            i.putExtra("address", "Mumbai");
            i.putExtra("contact", "9876543210");

            startActivity(i);
        });
    }
}
