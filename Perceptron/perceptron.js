class Perceptron{
    
    constructor(w1, w2, b){
        this.w1 = w1;
        this.w2 = w2;
        this.b = b;
        this.yout = [];
    }

    //Takes the input and target arrays.
    input(x1, x2, t){
        for(let i = 0;i<4;i++){
            let yput;
            let yin = this.w1*x1[i] + this.w2*x2[i] + this.b;
            if(yin >= 0){
                yput = 1;
            }
            else{
                yput = 0;
            }

            this.update(yput, t[i], x1[i], x2[i]);
            this.yout[i] = yput;
        }
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
        let yput = this.w1*x1 + this.w2*x2 + 1;
        if(yput >= 0){
            y = 1;
        }
        else{
            y = 0;
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
var orGate = new Perceptron(0,0,0);
orGate.input([0,0,1,1], [0,1,0,1], [0,1,1,1]);
