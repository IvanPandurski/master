package com.pandurski.bettingtips;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageButton;

import com.google.firebase.FirebaseApp;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class yesterday_tips extends AppCompatActivity {
    InitializeTips yesterdayTips;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_yesterday_tips);

        yesterdayTips = new InitializeTips(this);
        yesterdayTips.Initialize();

        DatabaseReference ref_yesterdays_tips = DatabaseUtils.getDatabase().getReference().child("yesterday/");

        ref_yesterdays_tips.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {

                yesterdayTips.showData(dataSnapshot);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });

        ImageButton switch_activity = (ImageButton) findViewById(R.id.switch_activity2);

        switch_activity.setOnClickListener(v -> {
            SwitchActivity();
        });

    }

    private void SwitchActivity() {
        Intent intent = new Intent(this, todays_tips.class);
        startActivity(intent);
        overridePendingTransition(R.anim.slide_in_left,R.anim.slide_out_right);

    }

    @Override
    public void finish() {
        super.finish();
        overridePendingTransition(R.anim.slide_in_left, R.anim.slide_out_right);
    }
}
