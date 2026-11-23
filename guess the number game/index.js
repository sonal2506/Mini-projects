const frm=document.querySelector('#form');
let random=parseInt(Math.floor(Math.random()*100)+1);
const msg=document.querySelector('#msg');
const chances=document.querySelector('#chances');
const check=document.querySelector('#submit')
const restart=document.querySelector('#restart')

let remaining=10;
chances.innerHTML=remaining

 frm.addEventListener('submit',function(e){
    e.preventDefault()
    const guess=parseInt(document.querySelector('#guess').value)

    // chances.innerHTML = remaining;

    if(guess<=0 || guess>100 || isNaN(guess)){
        msg.innerHTML='Please enter a number between 1 to 100'
    }
    else if(remaining===0){
        msg.innerHTML='Sorry Game Over! Start Again'
    }
    else{
        remaining--;
        chances.innerHTML = remaining;
        if(guess=== random){
        msg.innerHTML='Congratulation you guessed it right. Click Restart'
        
        }
        else if(guess<random){
            msg.innerHTML='number is greater than your guess'
        }
        else if(guess>random){
            msg.innerHTML='number is lesser than your guess'
        }
    }   
 });

 restart.addEventListener('click', function(e){
    random=parseInt(Math.floor(Math.random()*100)+1)
    remaining=10
    chances.innerHTML=remaining;
    msg.innerHTML=''
    document.querySelector('#guess').value=''
 })