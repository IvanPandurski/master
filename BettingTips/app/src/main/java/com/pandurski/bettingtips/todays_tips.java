package com.pandurski.bettingtips;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.google.firebase.FirebaseApp;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import org.w3c.dom.Text;

import java.util.ArrayList;

public class todays_tips extends AppCompatActivity {
    private DatabaseReference mDatabase;

    ArrayList<TextView> league;
    {
        league = new ArrayList<>();
    }

    ArrayList<TextView> match_info;
    {
        match_info = new ArrayList<>();
    }

    ArrayList<TextView> predictions;
    {
        predictions = new ArrayList<>();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_todays_tips);
        setLeague();
        setMatch_info();
        setPredictions();
        if(!FirebaseApp.getApps(this).isEmpty()) {
            FirebaseDatabase.getInstance().setPersistenceEnabled(true);
        }

        mDatabase = FirebaseDatabase.getInstance().getReference();

        DatabaseReference ref = mDatabase.child("today/");

        ref.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {

                showData(dataSnapshot);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });


    }

    private void showData(DataSnapshot dataSnapshot) {
        int i = 0;
        for(DataSnapshot ds : dataSnapshot.getChildren())
        {
            Prediction tip = ds.getValue(Prediction.class);

            league.get(i).setText(tip.league);
            match_info.get(i).setText(tip.match_info);
            predictions.get(i).setText(tip.prediction);
            i++;
       }

    }

    private void setLeague()
    {
        league.add((TextView) findViewById(R.id.league_one));
        league.add((TextView) findViewById(R.id.league_two));
        league.add((TextView) findViewById(R.id.league_three));
        league.add((TextView) findViewById(R.id.league_four));
    }

    private void setMatch_info()
    {
        match_info.add((TextView) findViewById(R.id.match_information_one));
        match_info.add((TextView) findViewById(R.id.match_information_two));
        match_info.add((TextView) findViewById(R.id.match_information_three));
        match_info.add((TextView) findViewById(R.id.match_information_four));
    }

    private void setPredictions()
    {
        predictions.add((TextView) findViewById(R.id.prediction_one));
        predictions.add((TextView) findViewById(R.id.prediction_two));
        predictions.add((TextView) findViewById(R.id.prediction_three));
        predictions.add((TextView) findViewById(R.id.prediction_four));
    }

}
