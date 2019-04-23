class Perceptron{
    
    constructor(w1, w2, b, inputType){
        this.w1 = w1;
        this.w2 = w2;
        this.b = b;
        this.inputType = inputType;
        this.yout = [];
    }

    binaryThreshold(yin){
        if(yin >= 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    bipolarThreshold(yin){
        if(yin > 0){
            return 1;
        }
        else if(yin < 0){
            return -1;
        }
        else{
            return 0;
        }
    }

    //Takes the input and target arrays.
    input(x1, x2, t){
        for(let i = 0;i<4;i++){
            let yin = this.w1*x1[i] + this.w2*x2[i] + this.b;
            let yput;
            if(this.inputType === "binary"){
                yput = this.binaryThreshold(yin);
            }
            else{
                yput = this.bipolarThreshold(yin);
            }

            this.update(yput, t[i], x1[i], x2[i]);
            this.yout[i] = yput;
        }

        //Check If target values are equal to the computed output.
        //If yes, terminate the program else compute the next epoch.
        if(this.check(this.yout, t)){
            this.print();
        }
        else{
            this.input(x1, x2, t);
        }
    }

    //Updates the weights.
    update(y, t, x1, x2){
        this.w1 += 1*(t-y)*x1;
        this.w2 += 1*(t-y)*x2;
        this.b += 1*(t-y);
    }

    //Checks if the calculated values are equal to the target values.
    check(yout, t){
        if(yout.toString() === t.toString()){
            return true;
        }
        else{
            return false;
        }
    }

    //Gives the output of the trained network.
    output(x1, x2){
        let y;
        let yin = this.w1*x1 + this.w2*x2 + 1;
        if(this.inputType === "binary"){
            y = this.binaryThreshold(yin);
        }
        else{
            y = this.bipolarThreshold(yin);
        }

        console.log(y);
    }

    //Prints the final weights.
    print(){
    console.log(this.w1);
    console.log(this.w2);
    console.log(this.b);
    }
}

//A new instance of Perceptron class is created.
var orGateBinary = new Perceptron(0,0,0,"binary");
orGateBinary.input([0,0,1,1], [0,1,0,1], [0,1,1,1]);

var orGateBipolar = new Perceptron(0,0,0,"bipolar");
orGateBipolar.input([-1,-1,1,1], [-1,1,-1,1], [-1,1,1,1]);
