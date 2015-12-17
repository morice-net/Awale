import QtQuick 2.3
import QtGraphicalEffects 1.0
import QtQuick.Particles 2.0

//import "QML/JavaScript/Palette.js" as Palette
//import "QML"

ParticleSystem {
    id: particles
    anchors.fill: parent

    property var next: []

    ImageParticle {
        source: "../Images/Star.png"
        alpha: 0.8
        colorVariation: 0.1
    }
    
    Emitter {
        id: pulseEmitter
        emitRate: 1000
        lifeSpan: 300
        enabled: false
        velocity: AngleDirection{magnitude: 64; angleVariation: 360}
        size: 45
        sizeVariation: 15
    }

    Timer {
       interval: 200; running: true; repeat: true
       onTriggered: {
           if (next.length !== 0) {
               var item = next.shift();
               var obj = mapFromItem(item);
               var rotation;
               if (obj.y > main.height/2)
                   rotation = 1;
               else
                   rotation = -1;

               var xBurst = obj.x + rotation*item.width/2;
               var yBurst = obj.y + rotation*item.height/2;
               pulseEmitter.burst(10, xBurst, yBurst);
           }
       }
   }
    function pulse(item) {
        next.push(item);

    }
}
