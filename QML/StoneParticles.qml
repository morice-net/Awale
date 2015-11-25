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
        alpha: 0
        colorVariation: 0.6
    }
    
    Emitter {
        id: pulseEmitter
        emitRate: 1000
        lifeSpan: 300
        enabled: false
        velocity: AngleDirection{magnitude: 64; angleVariation: 360}
        size: 15
        sizeVariation: 8
    }

    Timer {
       interval: 500; running: true; repeat: true
       onTriggered: {
           if (next.length === 0) {
               var obj = mapFromItem(next.shift());
               pulseEmitter.burst(50, obj.x , obj.y);
           }
       }
   }
    function pulse(item) {
        next.push(item);

    }
}
