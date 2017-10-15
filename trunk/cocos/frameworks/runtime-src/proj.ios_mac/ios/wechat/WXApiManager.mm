//
//  WXApiManager.mm
//  mahjong
//
//  Created by connor on 2017/10/12.
//

#import "WXApiManager.h"
#import "WXApi.h"
#import "cocos/scripting/lua-bindings/manual/CCLuaBridge.h"
#import "cocos/scripting/lua-bindings/manual/CCLuaEngine.h"

@implementation WXApiManager

+(void)shareImage:(NSDictionary*)dict{
    NSString *imageName = [dict valueForKey:@"image_name"];
    id wxScene = [dict valueForKey:@"wx_scene"];
    
    if (nil == imageName || nil == wxScene)
        return;
    
    NSString *docDir = [NSHomeDirectory() stringByAppendingString:@"/Documents/"];
    NSString *imagePath = [docDir stringByAppendingString:imageName];
    NSData *imageData = [NSData dataWithContentsOfFile:imagePath];
    
    if (nil == imageData)
        return;
    
    //UIImage *imageTmp = [UIImage imageNamed:imageName];
    //[UIImagePNGRepresentation(imageTmp) writeToFile:imagePath atomically:YES];

    //UIImage *image = [UIImage imageWithContentsOfFile:imagePath];
    //imageObj.imageData = UIImagePNGRepresentation(image);
    
    CGSize newSize = { 300, 200 };
    UIGraphicsBeginImageContext(newSize);
    UIImage *image = [UIImage imageWithData:imageData];
    [image drawInRect:CGRectMake(0, 0, newSize.width, newSize.height)];
    UIImage* thumbImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
  
    //[WXApi registerApp:@"wxffbcfc5a28b14217" enableMTA:YES];
    [WXApi registerApp:@"wxffbcfc5a28b14217"];
    
    WXImageObject *imageObj = [WXImageObject object];
    imageObj.imageData = imageData;
    
    WXMediaMessage *msg = [WXMediaMessage message];
    msg.mediaObject = imageObj;
    [msg setThumbImage:thumbImage];
     
    SendMessageToWXReq *req = [[SendMessageToWXReq alloc] init];
    req.bText = NO;
    req.message = msg;
    req.scene = [wxScene intValue];
    
    bool ret = [WXApi sendReq:req];
    NSLog(@"[WXApiManager:shareImage] ret : %d", ret);
}

@end
