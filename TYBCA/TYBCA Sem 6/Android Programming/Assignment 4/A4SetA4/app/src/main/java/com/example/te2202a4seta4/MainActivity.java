package com.example.te2202a4seta4;

import android.os.Bundle;
import android.widget.ImageView;
import android.widget.ToggleButton;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    ImageView imgBulb;
    ToggleButton toggleBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        imgBulb = findViewById(R.id.imgBulb);
        toggleBtn = findViewById(R.id.toggleBtn);

        toggleBtn.setOnCheckedChangeListener((buttonView, isChecked) -> {
            if (isChecked) {
                imgBulb.setImageResource(R.drawable.bulb_on);
            } else {
                imgBulb.setImageResource(R.drawable.bulb_off);
            }
        });
    }
}
