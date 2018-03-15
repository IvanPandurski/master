package com.example.jsonapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    Button click;
    public static TextView data;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        click = (Button) findViewById(R.id.btn1);
        data = (TextView) findViewById(R.id.data);

        click.setOnClickListener(v -> {
            fetchData process = new fetchData();
            process.execute();
        });
    }
}
