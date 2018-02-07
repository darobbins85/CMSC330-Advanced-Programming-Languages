/*
 * File: P1.java
 * Author: David Robbins
 * Date: 2017.11.19
 * Purpose: Create a GUI by parsing a text file following the provided grammar in project 1 instructions
 */

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;
import javax.swing.*;

public class P1 {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        Gui test = new Gui(input);
    }

    static class Gui {
        
        //create class variables, which many take advantage of being able to be 
        //reassigned in a method and then reallocated in another and reused
        JFrame frame;
        String title, layout, temp = "", mainToken;
        JPanel jp; JButton jb; JLabel jl; JTextField tf; ButtonGroup bg; JRadioButton rb;
        FlowLayout flow; GridLayout grid;
        int width, height;
        
        //contructor
        public Gui(String file) throws FileNotFoundException{
            //the Gui constructor only needs the name of the file to run the program
            //first converting the file into a buffered reader, then scanning the file
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);           
            Scanner scan = new Scanner(fr);
            String input = "";
            
            //next I iterated through the scanner to create one string of all 
            //of the values in the text file
            while(scan.hasNext()){
                input = input + scan.next() + " ";
            }
            
            //I chose to remove all of the punctuation so as long as the input files
            //do not have any syntax errors, the program will run without any problem
            input = input.replaceAll("[(),:;.]", "");
            
            //There was one problem in the example provided where there was no space
            //between the Grid keyword and the opening parenthesis, when I removed the
            //punctuation this caused an issue easily solved by adding a space after Grid
            input = input.replace("Grid", "Grid ");
            
            //next I tokenized the string to make it easier to work with using a 
            //class I am familiar with
            StringTokenizer tokenizer = new StringTokenizer(input);

            //As long as the tokenizer has more tokens, this loop will run
            while(tokenizer.hasMoreTokens()){
                
                //If temp is allocated to "Panel" then there is a nested Panel that will
                //be created later down the line so mainToken needs to be assigned to "Panel"
                //If not, then mainToken assigns to whatever object keyword needed
                if(temp.equals("Panel")){
                    mainToken = "Panel";
                }else{
                    mainToken = tokenizer.nextToken();
                }
                
                //If Window is the next token, this loop will start the Window production
                //which will in turn set the title, width and height of the JFrame frame
                if(mainToken.equals("Window")){
                    title = tokenizer.nextToken().replace("\"", "");
                    width = Integer.parseInt(tokenizer.nextToken());
                    height = Integer.parseInt(tokenizer.nextToken());
                    mainToken = tokenizer.nextToken();
                    frame = new JFrame(title);    
                    frame.setSize(width, height);
                } 
                
                //If Layout is the next token, this loop will set the Layout of the Window
                if(mainToken.equals("Layout")){
                    layout = tokenizer.nextToken();
                    if(layout.equals("Flow")){
                        flow = new FlowLayout();
                        frame.setLayout(flow);
                    } 
                    
                    if(layout.equals("Grid")){
                        grid = new GridLayout(
                                Integer.parseInt(tokenizer.nextToken()), 
                                Integer.parseInt(tokenizer.nextToken()));
                        temp = tokenizer.nextToken();
                        //This bit is in the case of Grids that have HGAP and VGAP assignments
                        if(temp.matches(".*\\d.*")){
                            grid.setHgap(Integer.parseInt(temp));
                            grid.setVgap(Integer.parseInt(tokenizer.nextToken()));
                            temp = tokenizer.nextToken();
                        }
                        frame.setLayout(grid);
                    }
                }
                
                //If Textfield is the next token, this will add a JTextField object to the Window
                if(mainToken.equals("Textfield")){
                    tf = new JTextField(Integer.parseInt(tokenizer.nextToken()));
                    frame.add(tf);
                }
                
                //If Button is the next token, this will add a JButton object to the Window
                if(mainToken.equals("Button")){
                    jb = new JButton(tokenizer.nextToken().replace("\"", ""));
                    frame.add(jb);
                }

                //If Label is the next token, this will add a JLabel object to the Window
                if(mainToken.equals("Label")){
                    jl = new JLabel(tokenizer.nextToken().replace("\"", ""));
                    frame.add(jl);
                }
                
                //If Group is the next token, this will add a ButtonGroup object to the Window
                if(mainToken.equals("Group")){
                    temp = tokenizer.nextToken();
                    bg = new ButtonGroup();
                    //After a button group is created, we loop through to see how many radio
                    //buttons to add to that group, and we add them to the frame as we make them
                    //as well as adding them to the group each time the token is equal to Radio
                    while(temp.equals("Radio")){
                        rb = new JRadioButton(tokenizer.nextToken().replace("\"", ""));
                        bg.add(rb);
                        frame.add(rb);
                        temp = tokenizer.nextToken();
                    }
                }

                //Basically what happens above happens again, but only if the token is equal
                //to Panel.  When it is, the temp variable is used in place of the mainToken
                //This part of the loop allows for nested Panels.  The rest of the loops
                //in this section of code will look similar to the above code
                if(mainToken.equals("Panel")){
                    jp = new JPanel();
                    temp = tokenizer.nextToken();
                    layout = tokenizer.nextToken();
                    if(layout.equals("Flow")){
                        flow = new FlowLayout();
                        jp.setLayout(flow);
                        temp = tokenizer.nextToken();
                    }

                    if(layout.equals("Grid")){
                        grid = new GridLayout(
                                Integer.parseInt(tokenizer.nextToken()), 
                                Integer.parseInt(tokenizer.nextToken()));
                        temp = tokenizer.nextToken();
                        
                        if(temp.matches(".*\\d.*")){
                            grid.setHgap(Integer.parseInt(temp));
                            grid.setVgap(Integer.parseInt(tokenizer.nextToken()));
                            temp = tokenizer.nextToken();
                        }
                        jp.setLayout(grid);
                        
                    }

                    while(temp.equals("Button") || 
                            temp.equals("Label") ||
                            temp.equals("Group") ||
                            temp.equals("Panel") ||
                            temp.equals("Textfield")){

                        while(temp.equals("Button")){
                            jb = new JButton(tokenizer.nextToken().replace("\"", ""));
                            jp.add(jb);
                            temp = tokenizer.nextToken();
                        }

                        while(temp.equals("Label")){                            
                            jl = new JLabel(tokenizer.nextToken().replace("\"", ""));
                            jp.add(jl);
                            temp = tokenizer.nextToken();
                        }

                        while(temp.equals("Textfield")){
                            tf = new JTextField(Integer.parseInt(tokenizer.nextToken()));
                            jp.add(tf);
                            temp = tokenizer.nextToken();
                        }

                        if(temp.equals("Group")){
                            temp = tokenizer.nextToken();
                            bg = new ButtonGroup();
                            while(temp.equals("Radio")){
                                rb = new JRadioButton(tokenizer.nextToken());
                                bg.add(rb);
                                jp.add(rb);
                                temp = tokenizer.nextToken();
                            }
                        }
                        
                        //This statement will set mainToken to Panel to let the program know
                        //when it begins the next loop through that there is a nested Panel
                        //that needs to be added on and if that Panel has another Panel in
                        //it, this statement will catch it and so on
                        if(temp.equals("Panel")){
                            mainToken = temp;
                            frame.add(jp);
                            break;
                        }
                        
                        //If temp does not equal to Panel, it should equal to End at this point
                        //unless there is syntax error and the nested Panel will be added to the
                        //main frame
                        if(temp.equals("End")){
                            frame.add(jp);
                        }
                    }
                }
            
            //This statement should catch the final End token which indicates that the frame
            //is finished being set up and can now be set to visible
            if(mainToken.equals("End")){
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setVisible(true);
            }
            
            //While not the prettiest way to catch syntax errors, it did the job...
            //I found that without this, the program continues to loop without throwing
            //an error to catch, so I did the following instead which did the trick
            if(!mainToken.equals("Window") &&
                    !mainToken.equals("Layout") &&
                    !mainToken.equals("Flow") &&
                    !mainToken.equals("Grid") &&
                    !mainToken.equals("Button") &&
                    !mainToken.equals("Group") &&
                    !mainToken.equals("Label") &&
                    !mainToken.equals("Panel") &&
                    !mainToken.equals("Textfield") &&
                    !mainToken.equals("Radio") &&
                    !mainToken.equals("End")){
                JOptionPane.showMessageDialog(frame, "There was a parsing error - adjust input and retry");
                System.exit(0);
            }

            }   
        }
    }
}