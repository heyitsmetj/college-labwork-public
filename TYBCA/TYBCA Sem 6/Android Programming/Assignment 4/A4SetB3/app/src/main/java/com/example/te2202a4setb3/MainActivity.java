package com.example.te2202a4setb3;

import android.os.Bundle;
import android.view.View;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageSwitcher;
import android.widget.ImageView;
import android.widget.ViewSwitcher;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    ImageSwitcher switcher;
    Button next, prev;

    int[] images = {
            R.drawable.img1,
            R.drawable.img2,
            R.drawable.img3,
    };

    int position = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        switcher = findViewById(R.id.imageSwitcher);
        next = findViewById(R.id.btnNext);
        prev = findViewById(R.id.btnPrev);

        // IMPORTANT PART (setFactory)
        switcher.setFactory(new ViewSwitcher.ViewFactory() {
            @Override
            public View makeView() {
                ImageView img = new ImageView(getApplicationContext());
                img.setScaleType(ImageView.ScaleType.FIT_CENTER);
                img.setLayoutParams(new ImageSwitcher.LayoutParams(
                        ImageSwitcher.LayoutParams.MATCH_PARENT,
                        ImageSwitcher.LayoutParams.MATCH_PARENT));
                return img;
            }
        });

        // animation
        switcher.setInAnimation(AnimationUtils.loadAnimation(this, android.R.anim.slide_in_left));
        switcher.setOutAnimation(AnimationUtils.loadAnimation(this, android.R.anim.slide_out_right));

        // first image
        switcher.setImageResource(images[position]);

        next.setOnClickListener(v -> {
            position++;
            if(position >= images.length)
                position = 0;
            switcher.setImageResource(images[position]);
        });

        prev.setOnClickListener(v -> {
            position--;
            if(position < 0)
                position = images.length - 1;
            switcher.setImageResource(images[position]);
        });
    }
}