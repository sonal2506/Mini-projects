const start=document.getElementById('start')
const stop=document.getElementById('stop')

const randomColor=function(){
    const hex='0123456789ABCDEF'
    let color='#'
    for(let i=0; i<6; i++){
        color+=hex[Math.floor(Math.random()*16)]
    }
    return color
}
let intervalId
function startChnagingColor(){
    if(!intervalId){
        intervalId=setInterval(changecolor,1000)
    }

    function changecolor(){
        document.body.style.backgroundColor=randomColor()
    }
}
function stopChnagingColor(){
    clearInterval(intervalId)
    intervalId=null
}
start.addEventListener('click',startChnagingColor)

stop.addEventListener('click',stopChnagingColor)

document.querySelector('#reset').addEventListener('click', function(){
    document.body.style.backgroundColor='white'
})