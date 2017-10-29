// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: play_card_msg_protocol.proto

#ifndef PROTOBUF_play_5fcard_5fmsg_5fprotocol_2eproto__INCLUDED
#define PROTOBUF_play_5fcard_5fmsg_5fprotocol_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "msg/protocol/ting_card_msg_protocol.pb.h"
// @@protoc_insertion_point(includes)

namespace gamer {
namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_play_5fcard_5fmsg_5fprotocol_2eproto();
void protobuf_AssignDesc_play_5fcard_5fmsg_5fprotocol_2eproto();
void protobuf_ShutdownFile_play_5fcard_5fmsg_5fprotocol_2eproto();

class PlayCardMsgProtocol;

// ===================================================================

class PlayCardMsgProtocol : public ::google::protobuf::Message {
 public:
  PlayCardMsgProtocol();
  virtual ~PlayCardMsgProtocol();

  PlayCardMsgProtocol(const PlayCardMsgProtocol& from);

  inline PlayCardMsgProtocol& operator=(const PlayCardMsgProtocol& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PlayCardMsgProtocol& default_instance();

  void Swap(PlayCardMsgProtocol* other);

  // implements Message ----------------------------------------------

  PlayCardMsgProtocol* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PlayCardMsgProtocol& from);
  void MergeFrom(const PlayCardMsgProtocol& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 player_id = 1;
  inline bool has_player_id() const;
  inline void clear_player_id();
  static const int kPlayerIdFieldNumber = 1;
  inline ::google::protobuf::int32 player_id() const;
  inline void set_player_id(::google::protobuf::int32 value);

  // required int32 room_id = 2;
  inline bool has_room_id() const;
  inline void clear_room_id();
  static const int kRoomIdFieldNumber = 2;
  inline ::google::protobuf::int32 room_id() const;
  inline void set_room_id(::google::protobuf::int32 value);

  // required int32 cur_round = 3;
  inline bool has_cur_round() const;
  inline void clear_cur_round();
  static const int kCurRoundFieldNumber = 3;
  inline ::google::protobuf::int32 cur_round() const;
  inline void set_cur_round(::google::protobuf::int32 value);

  // required int32 operation_id = 4;
  inline bool has_operation_id() const;
  inline void clear_operation_id();
  static const int kOperationIdFieldNumber = 4;
  inline ::google::protobuf::int32 operation_id() const;
  inline void set_operation_id(::google::protobuf::int32 value);

  // optional int32 discard = 5 [default = -1];
  inline bool has_discard() const;
  inline void clear_discard();
  static const int kDiscardFieldNumber = 5;
  inline ::google::protobuf::int32 discard() const;
  inline void set_discard(::google::protobuf::int32 value);

  // optional int32 new_card = 6 [default = -1];
  inline bool has_new_card() const;
  inline void clear_new_card();
  static const int kNewCardFieldNumber = 6;
  inline ::google::protobuf::int32 new_card() const;
  inline void set_new_card(::google::protobuf::int32 value);

  // optional int32 next_operate_player_id = 7 [default = 0];
  inline bool has_next_operate_player_id() const;
  inline void clear_next_operate_player_id();
  static const int kNextOperatePlayerIdFieldNumber = 7;
  inline ::google::protobuf::int32 next_operate_player_id() const;
  inline void set_next_operate_player_id(::google::protobuf::int32 value);

  // optional bool has_next_operate_player_new_card = 8 [default = false];
  inline bool has_has_next_operate_player_new_card() const;
  inline void clear_has_next_operate_player_new_card();
  static const int kHasNextOperatePlayerNewCardFieldNumber = 8;
  inline bool has_next_operate_player_new_card() const;
  inline void set_has_next_operate_player_new_card(bool value);

  // optional int32 my_available_operation_id = 9 [default = -1];
  inline bool has_my_available_operation_id() const;
  inline void clear_my_available_operation_id();
  static const int kMyAvailableOperationIdFieldNumber = 9;
  inline ::google::protobuf::int32 my_available_operation_id() const;
  inline void set_my_available_operation_id(::google::protobuf::int32 value);

  // repeated int32 operating_cards = 10;
  inline int operating_cards_size() const;
  inline void clear_operating_cards();
  static const int kOperatingCardsFieldNumber = 10;
  inline ::google::protobuf::int32 operating_cards(int index) const;
  inline void set_operating_cards(int index, ::google::protobuf::int32 value);
  inline void add_operating_cards(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      operating_cards() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_operating_cards();

  // repeated int32 invisible_hand_cards = 11;
  inline int invisible_hand_cards_size() const;
  inline void clear_invisible_hand_cards();
  static const int kInvisibleHandCardsFieldNumber = 11;
  inline ::google::protobuf::int32 invisible_hand_cards(int index) const;
  inline void set_invisible_hand_cards(int index, ::google::protobuf::int32 value);
  inline void add_invisible_hand_cards(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      invisible_hand_cards() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_invisible_hand_cards();

  // repeated .gamer.protocol.TingCardMsgProtocol ting_cards = 12;
  inline int ting_cards_size() const;
  inline void clear_ting_cards();
  static const int kTingCardsFieldNumber = 12;
  inline const ::gamer::protocol::TingCardMsgProtocol& ting_cards(int index) const;
  inline ::gamer::protocol::TingCardMsgProtocol* mutable_ting_cards(int index);
  inline ::gamer::protocol::TingCardMsgProtocol* add_ting_cards();
  inline const ::google::protobuf::RepeatedPtrField< ::gamer::protocol::TingCardMsgProtocol >&
      ting_cards() const;
  inline ::google::protobuf::RepeatedPtrField< ::gamer::protocol::TingCardMsgProtocol >*
      mutable_ting_cards();

  // @@protoc_insertion_point(class_scope:gamer.protocol.PlayCardMsgProtocol)
 private:
  inline void set_has_player_id();
  inline void clear_has_player_id();
  inline void set_has_room_id();
  inline void clear_has_room_id();
  inline void set_has_cur_round();
  inline void clear_has_cur_round();
  inline void set_has_operation_id();
  inline void clear_has_operation_id();
  inline void set_has_discard();
  inline void clear_has_discard();
  inline void set_has_new_card();
  inline void clear_has_new_card();
  inline void set_has_next_operate_player_id();
  inline void clear_has_next_operate_player_id();
  inline void set_has_has_next_operate_player_new_card();
  inline void clear_has_has_next_operate_player_new_card();
  inline void set_has_my_available_operation_id();
  inline void clear_has_my_available_operation_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 player_id_;
  ::google::protobuf::int32 room_id_;
  ::google::protobuf::int32 cur_round_;
  ::google::protobuf::int32 operation_id_;
  ::google::protobuf::int32 discard_;
  ::google::protobuf::int32 new_card_;
  ::google::protobuf::int32 next_operate_player_id_;
  bool has_next_operate_player_new_card_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > operating_cards_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > invisible_hand_cards_;
  ::google::protobuf::RepeatedPtrField< ::gamer::protocol::TingCardMsgProtocol > ting_cards_;
  ::google::protobuf::int32 my_available_operation_id_;
  friend void  protobuf_AddDesc_play_5fcard_5fmsg_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_play_5fcard_5fmsg_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_play_5fcard_5fmsg_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static PlayCardMsgProtocol* default_instance_;
};
// ===================================================================


// ===================================================================

// PlayCardMsgProtocol

// required int32 player_id = 1;
inline bool PlayCardMsgProtocol::has_player_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PlayCardMsgProtocol::set_has_player_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PlayCardMsgProtocol::clear_has_player_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PlayCardMsgProtocol::clear_player_id() {
  player_id_ = 0;
  clear_has_player_id();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::player_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.player_id)
  return player_id_;
}
inline void PlayCardMsgProtocol::set_player_id(::google::protobuf::int32 value) {
  set_has_player_id();
  player_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.player_id)
}

// required int32 room_id = 2;
inline bool PlayCardMsgProtocol::has_room_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PlayCardMsgProtocol::set_has_room_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PlayCardMsgProtocol::clear_has_room_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PlayCardMsgProtocol::clear_room_id() {
  room_id_ = 0;
  clear_has_room_id();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::room_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.room_id)
  return room_id_;
}
inline void PlayCardMsgProtocol::set_room_id(::google::protobuf::int32 value) {
  set_has_room_id();
  room_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.room_id)
}

// required int32 cur_round = 3;
inline bool PlayCardMsgProtocol::has_cur_round() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PlayCardMsgProtocol::set_has_cur_round() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PlayCardMsgProtocol::clear_has_cur_round() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PlayCardMsgProtocol::clear_cur_round() {
  cur_round_ = 0;
  clear_has_cur_round();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::cur_round() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.cur_round)
  return cur_round_;
}
inline void PlayCardMsgProtocol::set_cur_round(::google::protobuf::int32 value) {
  set_has_cur_round();
  cur_round_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.cur_round)
}

// required int32 operation_id = 4;
inline bool PlayCardMsgProtocol::has_operation_id() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PlayCardMsgProtocol::set_has_operation_id() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PlayCardMsgProtocol::clear_has_operation_id() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PlayCardMsgProtocol::clear_operation_id() {
  operation_id_ = 0;
  clear_has_operation_id();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::operation_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.operation_id)
  return operation_id_;
}
inline void PlayCardMsgProtocol::set_operation_id(::google::protobuf::int32 value) {
  set_has_operation_id();
  operation_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.operation_id)
}

// optional int32 discard = 5 [default = -1];
inline bool PlayCardMsgProtocol::has_discard() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PlayCardMsgProtocol::set_has_discard() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PlayCardMsgProtocol::clear_has_discard() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PlayCardMsgProtocol::clear_discard() {
  discard_ = -1;
  clear_has_discard();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::discard() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.discard)
  return discard_;
}
inline void PlayCardMsgProtocol::set_discard(::google::protobuf::int32 value) {
  set_has_discard();
  discard_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.discard)
}

// optional int32 new_card = 6 [default = -1];
inline bool PlayCardMsgProtocol::has_new_card() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void PlayCardMsgProtocol::set_has_new_card() {
  _has_bits_[0] |= 0x00000020u;
}
inline void PlayCardMsgProtocol::clear_has_new_card() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void PlayCardMsgProtocol::clear_new_card() {
  new_card_ = -1;
  clear_has_new_card();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::new_card() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.new_card)
  return new_card_;
}
inline void PlayCardMsgProtocol::set_new_card(::google::protobuf::int32 value) {
  set_has_new_card();
  new_card_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.new_card)
}

// optional int32 next_operate_player_id = 7 [default = 0];
inline bool PlayCardMsgProtocol::has_next_operate_player_id() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void PlayCardMsgProtocol::set_has_next_operate_player_id() {
  _has_bits_[0] |= 0x00000040u;
}
inline void PlayCardMsgProtocol::clear_has_next_operate_player_id() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void PlayCardMsgProtocol::clear_next_operate_player_id() {
  next_operate_player_id_ = 0;
  clear_has_next_operate_player_id();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::next_operate_player_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.next_operate_player_id)
  return next_operate_player_id_;
}
inline void PlayCardMsgProtocol::set_next_operate_player_id(::google::protobuf::int32 value) {
  set_has_next_operate_player_id();
  next_operate_player_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.next_operate_player_id)
}

// optional bool has_next_operate_player_new_card = 8 [default = false];
inline bool PlayCardMsgProtocol::has_has_next_operate_player_new_card() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void PlayCardMsgProtocol::set_has_has_next_operate_player_new_card() {
  _has_bits_[0] |= 0x00000080u;
}
inline void PlayCardMsgProtocol::clear_has_has_next_operate_player_new_card() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void PlayCardMsgProtocol::clear_has_next_operate_player_new_card() {
  has_next_operate_player_new_card_ = false;
  clear_has_has_next_operate_player_new_card();
}
inline bool PlayCardMsgProtocol::has_next_operate_player_new_card() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.has_next_operate_player_new_card)
  return has_next_operate_player_new_card_;
}
inline void PlayCardMsgProtocol::set_has_next_operate_player_new_card(bool value) {
  set_has_has_next_operate_player_new_card();
  has_next_operate_player_new_card_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.has_next_operate_player_new_card)
}

// optional int32 my_available_operation_id = 9 [default = -1];
inline bool PlayCardMsgProtocol::has_my_available_operation_id() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void PlayCardMsgProtocol::set_has_my_available_operation_id() {
  _has_bits_[0] |= 0x00000100u;
}
inline void PlayCardMsgProtocol::clear_has_my_available_operation_id() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void PlayCardMsgProtocol::clear_my_available_operation_id() {
  my_available_operation_id_ = -1;
  clear_has_my_available_operation_id();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::my_available_operation_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.my_available_operation_id)
  return my_available_operation_id_;
}
inline void PlayCardMsgProtocol::set_my_available_operation_id(::google::protobuf::int32 value) {
  set_has_my_available_operation_id();
  my_available_operation_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.my_available_operation_id)
}

// repeated int32 operating_cards = 10;
inline int PlayCardMsgProtocol::operating_cards_size() const {
  return operating_cards_.size();
}
inline void PlayCardMsgProtocol::clear_operating_cards() {
  operating_cards_.Clear();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::operating_cards(int index) const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.operating_cards)
  return operating_cards_.Get(index);
}
inline void PlayCardMsgProtocol::set_operating_cards(int index, ::google::protobuf::int32 value) {
  operating_cards_.Set(index, value);
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.operating_cards)
}
inline void PlayCardMsgProtocol::add_operating_cards(::google::protobuf::int32 value) {
  operating_cards_.Add(value);
  // @@protoc_insertion_point(field_add:gamer.protocol.PlayCardMsgProtocol.operating_cards)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
PlayCardMsgProtocol::operating_cards() const {
  // @@protoc_insertion_point(field_list:gamer.protocol.PlayCardMsgProtocol.operating_cards)
  return operating_cards_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
PlayCardMsgProtocol::mutable_operating_cards() {
  // @@protoc_insertion_point(field_mutable_list:gamer.protocol.PlayCardMsgProtocol.operating_cards)
  return &operating_cards_;
}

// repeated int32 invisible_hand_cards = 11;
inline int PlayCardMsgProtocol::invisible_hand_cards_size() const {
  return invisible_hand_cards_.size();
}
inline void PlayCardMsgProtocol::clear_invisible_hand_cards() {
  invisible_hand_cards_.Clear();
}
inline ::google::protobuf::int32 PlayCardMsgProtocol::invisible_hand_cards(int index) const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.invisible_hand_cards)
  return invisible_hand_cards_.Get(index);
}
inline void PlayCardMsgProtocol::set_invisible_hand_cards(int index, ::google::protobuf::int32 value) {
  invisible_hand_cards_.Set(index, value);
  // @@protoc_insertion_point(field_set:gamer.protocol.PlayCardMsgProtocol.invisible_hand_cards)
}
inline void PlayCardMsgProtocol::add_invisible_hand_cards(::google::protobuf::int32 value) {
  invisible_hand_cards_.Add(value);
  // @@protoc_insertion_point(field_add:gamer.protocol.PlayCardMsgProtocol.invisible_hand_cards)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
PlayCardMsgProtocol::invisible_hand_cards() const {
  // @@protoc_insertion_point(field_list:gamer.protocol.PlayCardMsgProtocol.invisible_hand_cards)
  return invisible_hand_cards_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
PlayCardMsgProtocol::mutable_invisible_hand_cards() {
  // @@protoc_insertion_point(field_mutable_list:gamer.protocol.PlayCardMsgProtocol.invisible_hand_cards)
  return &invisible_hand_cards_;
}

// repeated .gamer.protocol.TingCardMsgProtocol ting_cards = 12;
inline int PlayCardMsgProtocol::ting_cards_size() const {
  return ting_cards_.size();
}
inline void PlayCardMsgProtocol::clear_ting_cards() {
  ting_cards_.Clear();
}
inline const ::gamer::protocol::TingCardMsgProtocol& PlayCardMsgProtocol::ting_cards(int index) const {
  // @@protoc_insertion_point(field_get:gamer.protocol.PlayCardMsgProtocol.ting_cards)
  return ting_cards_.Get(index);
}
inline ::gamer::protocol::TingCardMsgProtocol* PlayCardMsgProtocol::mutable_ting_cards(int index) {
  // @@protoc_insertion_point(field_mutable:gamer.protocol.PlayCardMsgProtocol.ting_cards)
  return ting_cards_.Mutable(index);
}
inline ::gamer::protocol::TingCardMsgProtocol* PlayCardMsgProtocol::add_ting_cards() {
  // @@protoc_insertion_point(field_add:gamer.protocol.PlayCardMsgProtocol.ting_cards)
  return ting_cards_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::gamer::protocol::TingCardMsgProtocol >&
PlayCardMsgProtocol::ting_cards() const {
  // @@protoc_insertion_point(field_list:gamer.protocol.PlayCardMsgProtocol.ting_cards)
  return ting_cards_;
}
inline ::google::protobuf::RepeatedPtrField< ::gamer::protocol::TingCardMsgProtocol >*
PlayCardMsgProtocol::mutable_ting_cards() {
  // @@protoc_insertion_point(field_mutable_list:gamer.protocol.PlayCardMsgProtocol.ting_cards)
  return &ting_cards_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace gamer

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_play_5fcard_5fmsg_5fprotocol_2eproto__INCLUDED
