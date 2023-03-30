package com.example.klarisa2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void goBt (View view){
        Intent myIntent = new Intent (MainActivity.this, BLEActivity.class);
        startActivity(myIntent);
    }

    public void exitActivity (View view) {
        finish();
    }
}