package com.pandurski.bettingtips;

import com.google.firebase.database.FirebaseDatabase;

/**
 * Created by ivan pandurski on 3/20/18.
 */

public class DatabaseUtils {
    private static FirebaseDatabase mDatabase;

    public static FirebaseDatabase getDatabase() {
        if (mDatabase == null) {
            mDatabase = FirebaseDatabase.getInstance();
            mDatabase.setPersistenceEnabled(true);
        }
        return mDatabase;
    }

}