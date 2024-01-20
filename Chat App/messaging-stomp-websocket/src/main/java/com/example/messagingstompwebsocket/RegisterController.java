package com.example.messagingstompwebsocket;

import org.springframework.web.bind.annotation.*;

import java.io.*;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/register/")
public class RegisterController {
    RegisterController(){
        System.out.println("Registered ");
    }
    public class AppendingObjectOutputStream extends ObjectOutputStream {

        public AppendingObjectOutputStream(OutputStream out) throws IOException {
            super(out);
        }

        @Override
        protected void writeStreamHeader() throws IOException {
            // do not write a header, but reset:
            // this line added after another question
            // showed a problem with the original
            reset();
        }

    }

    @CrossOrigin
    @PostMapping
    public Object registerUser(@RequestBody User user)
    {
//            File file = new File("../resources/data/
               // Desired current working directory

//        File file = new File("user.dat");
//
//        FileOutputStream fos ;
//        ObjectOutputStream out;


        File file = new File("user.dat");
        boolean append = file.exists(); // if file exists then append, otherwise create new

        if(append){
            try(ObjectInputStream input = new ObjectInputStream(new FileInputStream(file))){
                int f = 0;
                while(true){
                    User ll = (User)input.readObject();

                    if(ll != null){
                        ll.display();
                        System.out.println(ll.getEmail() + " " + user.getEmail());
                        if(user.getEmail().equals(ll.getEmail())){
                            f = 1;
                            input.close();
                            break;

                        }
                    }else{
                        input.close();
                        break;
                    }
                }
                if( f == 1){
                    Map<String, Object> object = new HashMap<>();
                    object.put("status", false);
//                return object;
                    return object;

                }else{
                    Map<String, Object> object = new HashMap<>();

                    object.put("status", true);
//                return object;
                    return object;

                }
//            input.close();
            }catch(Exception e ){
                System.out.println(e);
            }
        }


        try (
                FileOutputStream fout = new FileOutputStream(file, append);
                AppendableObjectOutputStream oout = new AppendableObjectOutputStream(fout, append);
        ) {
            oout.writeObject(user); // replace "..." with serializable object to be written
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }



//            try(ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(file, true))){
//
//                System.out.println("Writing!!");
//                output.writeObject(user);
//                user.display();
//                output.close();
//            }catch(Exception e ){
//                System.out.println(e);
//            }


        try( ObjectInputStream inp = new ObjectInputStream(new FileInputStream(file))){
            System.out.println("Entered in file!!");
            while(true){
                User currentUSer = (User)inp.readObject();
                if(currentUSer != null){
                    System.out.println("counted!!");
                    currentUSer.display();
                }else{
                    break;
                }
            }
        }catch(StreamCorruptedException ex){
            System.out.println(ex);
        }catch(Exception e){
            System.out.println(e);
        }

        Map<String, Object> object = new HashMap<>();
        object.put("status", true);
        return object;





    }
}
