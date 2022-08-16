//
//  PreventLock.m
//  edo
//
//  Created by Peter Varga on 2016. 02. 06..
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PreventLock.h"

void PreventLock::setTimerDisabled() {
    [[UIApplication sharedApplication] setIdleTimerDisabled: YES];
    }
