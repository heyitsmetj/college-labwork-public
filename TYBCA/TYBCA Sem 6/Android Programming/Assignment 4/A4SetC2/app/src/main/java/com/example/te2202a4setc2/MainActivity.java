package com.example.te2202a4setc2;

import android.os.Bundle;
import android.os.Handler;
import android.view.Menu;
import android.view.MenuItem;
import android.view.animation.AnimationUtils;
import android.widget.ImageSwitcher;
import android.widget.ImageView;
import android.widget.ViewSwitcher;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    ImageSwitcher switcher;

    int[] images = {
            R.drawable.img1,
            R.drawable.img2,
            R.drawable.img3,
    };

    int position = 0;
    Handler handler = new Handler();
    Runnable runnable;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        switcher = findViewById(R.id.switcher);

        switcher.setFactory(new ViewSwitcher.ViewFactory() {
            @Override
            public ImageView makeView() {
                ImageView img = new ImageView(getApplicationContext());
                img.setScaleType(ImageView.ScaleType.FIT_CENTER);
                return img;
            }
        });

        switcher.setInAnimation(AnimationUtils.loadAnimation(this, android.R.anim.fade_in));
        switcher.setOutAnimation(AnimationUtils.loadAnimation(this, android.R.anim.fade_out));

        switcher.setImageResource(images[0]);
    }

    // menu create
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    // menu click
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        if(item.getItemId()==R.id.slide)
            startSlide();

        else if(item.getItemId()==R.id.stop)
            handler.removeCallbacks(runnable);

        return true;
    }

    // slideshow logic
    void startSlide(){

        runnable = new Runnable() {
            @Override
            public void run() {
                position++;
                if(position>=images.length)
                    position=0;

                switcher.setImageResource(images[position]);

                handler.postDelayed(this,2000); // change every 2 sec
            }
        };

        handler.post(runnable);
    }
}