#
#  Be sure to run `pod spec lint R360CrawlerSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "R360CrawlerSDK"
  s.version      = "1.1.9"
  s.summary      = "A R360CrawlerSDK of rong360, use for crawler data"

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  s.description  = <<-DESC
                   抓取数据的sdk，支持支付宝和淘宝，运营商，邮箱,  添加命令 pod 'R360CrawlerSDK'
                   DESC

  s.homepage     = "https://github.com/Rong360SDK/RDPCrawlerSDK"
  s.license      = "MIT"
  s.author             = { "wanghuijian" => "wanghuijian@rong360.com" }
  s.ios.deployment_target = "7.0"
  s.source       = { :git => "https://github.com/Rong360SDK/RDPCrawlerSDK.git", :tag => "1.1.9" }
  s.resource = 'RDPCrawlerSDK/RDPCrawlerSDK.framework/RDPCrawler.bundle'
  s.vendored_frameworks = 'RDPCrawlerSDK/RDPCrawlerSDK.framework'
  s.frameworks = 'UIKit', 'CFNetwork', 'Security'
  s.library = 'z', 'icucore', 'sqlite3'
  s.weak_frameworks = 'Photos'
  s.requires_arc     = true

end
