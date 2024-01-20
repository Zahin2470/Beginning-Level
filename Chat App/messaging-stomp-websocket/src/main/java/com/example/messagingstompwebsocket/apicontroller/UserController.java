package com.example.messagingstompwebsocket.apicontroller;

import com.example.messagingstompwebsocket.AppendableObjectOutputStream;
import com.example.messagingstompwebsocket.User;
import org.springframework.web.bind.annotation.*;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;


@RestController
@RequestMapping("/user/")
public class UserController {
    UserController(){
        System.out.println("User Loading!");
    }

    @CrossOrigin
    @GetMapping
    public ArrayList<User> getUser()
    {
//            File file = new File("../resources/data/
        // Desired current working directory

//        File file = new File("user.dat");
//
//        FileOutputStream fos ;
//        ObjectOutputStream out;


        File file = new File("user.dat");
        boolean append = file.exists(); // if file exists then append, otherwise create new

        ArrayList<User> ulist = new ArrayList<>();


        if(append){
            try(ObjectInputStream input = new ObjectInputStream(new FileInputStream(file))){

                int f = 0;
                while(true){
                    User ll = (User)input.readObject();

                    if(ll != null){
                        ulist.add(ll);

                    }else{
                        input.close();
                        break;
                    }
                }

            input.close();
            }catch(Exception e ){
                System.out.println(e);
            }
        }


        return ulist;



    }
}
