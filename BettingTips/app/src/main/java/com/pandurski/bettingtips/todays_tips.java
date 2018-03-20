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
import com.pandurski.bettingtips.DatabaseUtils;
public class todays_tips extends AppCompatActivity {
//    private DatabaseReference mDatabase;
    InitializeTips todaysTips;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_todays_tips);

        todaysTips = new InitializeTips(this);
        todaysTips.Initialize();

        DatabaseReference ref_todays_tips = DatabaseUtils.getDatabase().getReference().child("today/");

        ref_todays_tips.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {

                todaysTips.showData(dataSnapshot);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });



        ImageButton switch_activity = (ImageButton) findViewById(R.id.switch_activity);

        switch_activity.setOnClickListener(v -> {
            SwitchActivity();
        });

    }

    private void SwitchActivity() {
        Intent intent = new Intent(this, yesterday_tips.class);
        startActivity(intent);
        overridePendingTransition(R.anim.slide_in_right,R.anim.slide_out_left);
    }

    @Override
    public void finish() {
        super.finish();
        overridePendingTransition(R.anim.slide_in_right, R.anim.slide_out_left);
    }
}
