package com.example.te2202a3seta3;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText display;
    double num1=0,num2=0;
    String op="";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        display=findViewById(R.id.edtDisplay);
    }

    public void numberClick(View v){
        Button b=(Button)v;
        display.append(b.getText().toString());
    }

    public void operatorClick(View v){
        Button b=(Button)v;
        num1=Double.parseDouble(display.getText().toString());
        op=b.getText().toString();
        display.setText("");
    }

    public void equalClick(View v){
        num2=Double.parseDouble(display.getText().toString());
        double result=0;

        switch(op){
            case "+": result=num1+num2; break;
            case "-": result=num1-num2; break;
            case "*": result=num1*num2; break;
            case "/": result=num1/num2; break;
        }

        display.setText(String.valueOf(result));
    }

    public void clearClick(View v){
        display.setText("");
        num1=num2=0;
        op="";
    }
}