package com.example.messagingstompwebsocket;

import org.springframework.web.bind.annotation.*;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/login/")
public class LoginController  {
    LoginController(){
        System.out.println("Hello");
    }

    @CrossOrigin
    @PostMapping
    public User createUser(@RequestBody User user)
  {
      System.out.println("uSER PRINTING WHILE LOGIN!");
      user.display();
      File file = new File("user.dat");
      boolean append = file.exists();

      User  ret = new User();
      if(append){
          try(ObjectInputStream input = new ObjectInputStream(new FileInputStream(file))){

              int f = 0;
              while(true){
                  User ll = (User)input.readObject();

                  if(ll != null){
                      ll.display();
                      System.out.println(ll.getEmail() + " " + user.getEmail());
                      if(user.getEmail().equals(ll.getEmail()) && user.getPassword().equals(ll.getPassword())){
                          f = 1;
                          ret = new User(ll);
                          input.close();
                          break;
                      }
                  }else{
                      input.close();
                      break;
                  }
              }
              if( f == 1){
                  ret.setStatus("on");
                  return ret;
              }else{
                  ret.setStatus("off");
                  return ret;
              }
          }catch(Exception e ){
              System.out.println(e);
          }
      }
//    if(user.getUsername().equals("helo") && user.getPassword().equals("123")){
//      Map<String, Object> object = new HashMap<>();
//
//      User u  =new User("01715369857", "dsd@gmail.com", "123", "Rahman");
//
//      object.put("status", true);
//      object.put("username", user.getUsername());
//      object.put("date", new Date());
//      return u;
//    }
//    Map<String, Object> object = new HashMap<>();
//      User u  =new User( "", "", "", "");
//
//    object.put("status", false);
//    object.put("username", "");
//    object.put("date", "");
//    return u;
//    }
      ret.setStatus("off");
      return ret;
    }
}