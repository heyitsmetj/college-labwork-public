package com.example.te2202a4setb4;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    double balance = 10000;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.bank_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        int id = item.getItemId();

        if(id == R.id.withdraw){
            balance -= 500;
            Toast.makeText(this,"Withdraw ₹500",Toast.LENGTH_SHORT).show();
        }
        else if(id == R.id.deposit){
            balance += 500;
            Toast.makeText(this,"Deposit ₹500",Toast.LENGTH_SHORT).show();
        }
        else if(id == R.id.balance){
            Toast.makeText(this,"Balance: ₹"+balance,Toast.LENGTH_SHORT).show();
        }
        else if(id == R.id.exit){
            finish();
        }

        return true;
    }
}