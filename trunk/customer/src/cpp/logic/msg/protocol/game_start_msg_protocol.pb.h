// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game_start_msg_protocol.proto

#ifndef PROTOBUF_game_5fstart_5fmsg_5fprotocol_2eproto__INCLUDED
#define PROTOBUF_game_5fstart_5fmsg_5fprotocol_2eproto__INCLUDED

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
#include "player_cards_msg_protocol.pb.h"
// @@protoc_insertion_point(includes)

namespace gamer {
namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_game_5fstart_5fmsg_5fprotocol_2eproto();
void protobuf_AssignDesc_game_5fstart_5fmsg_5fprotocol_2eproto();
void protobuf_ShutdownFile_game_5fstart_5fmsg_5fprotocol_2eproto();

class GameStartMsgProtocol;

// ===================================================================

class GameStartMsgProtocol : public ::google::protobuf::Message {
 public:
  GameStartMsgProtocol();
  virtual ~GameStartMsgProtocol();

  GameStartMsgProtocol(const GameStartMsgProtocol& from);

  inline GameStartMsgProtocol& operator=(const GameStartMsgProtocol& from) {
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
  static const GameStartMsgProtocol& default_instance();

  void Swap(GameStartMsgProtocol* other);

  // implements Message ----------------------------------------------

  GameStartMsgProtocol* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GameStartMsgProtocol& from);
  void MergeFrom(const GameStartMsgProtocol& from);
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

  // required int32 room_id = 1;
  inline bool has_room_id() const;
  inline void clear_room_id();
  static const int kRoomIdFieldNumber = 1;
  inline ::google::protobuf::int32 room_id() const;
  inline void set_room_id(::google::protobuf::int32 value);

  // required int32 room_owner_id = 2;
  inline bool has_room_owner_id() const;
  inline void clear_room_owner_id();
  static const int kRoomOwnerIdFieldNumber = 2;
  inline ::google::protobuf::int32 room_owner_id() const;
  inline void set_room_owner_id(::google::protobuf::int32 value);

  // optional int32 players_num = 3;
  inline bool has_players_num() const;
  inline void clear_players_num();
  static const int kPlayersNumFieldNumber = 3;
  inline ::google::protobuf::int32 players_num() const;
  inline void set_players_num(::google::protobuf::int32 value);

  // optional int32 cur_round = 4;
  inline bool has_cur_round() const;
  inline void clear_cur_round();
  static const int kCurRoundFieldNumber = 4;
  inline ::google::protobuf::int32 cur_round() const;
  inline void set_cur_round(::google::protobuf::int32 value);

  // optional int32 total_round = 5;
  inline bool has_total_round() const;
  inline void clear_total_round();
  static const int kTotalRoundFieldNumber = 5;
  inline ::google::protobuf::int32 total_round() const;
  inline void set_total_round(::google::protobuf::int32 value);

  // optional int32 remain_cards_num = 6;
  inline bool has_remain_cards_num() const;
  inline void clear_remain_cards_num();
  static const int kRemainCardsNumFieldNumber = 6;
  inline ::google::protobuf::int32 remain_cards_num() const;
  inline void set_remain_cards_num(::google::protobuf::int32 value);

  // optional int32 banker_id = 7;
  inline bool has_banker_id() const;
  inline void clear_banker_id();
  static const int kBankerIdFieldNumber = 7;
  inline ::google::protobuf::int32 banker_id() const;
  inline void set_banker_id(::google::protobuf::int32 value);

  // optional int32 banker_is_same_time = 8;
  inline bool has_banker_is_same_time() const;
  inline void clear_banker_is_same_time();
  static const int kBankerIsSameTimeFieldNumber = 8;
  inline ::google::protobuf::int32 banker_is_same_time() const;
  inline void set_banker_is_same_time(::google::protobuf::int32 value);

  // optional int32 cur_acting_player_id = 9;
  inline bool has_cur_acting_player_id() const;
  inline void clear_cur_acting_player_id();
  static const int kCurActingPlayerIdFieldNumber = 9;
  inline ::google::protobuf::int32 cur_acting_player_id() const;
  inline void set_cur_acting_player_id(::google::protobuf::int32 value);

  // optional int32 cur_action_id = 10;
  inline bool has_cur_action_id() const;
  inline void clear_cur_action_id();
  static const int kCurActionIdFieldNumber = 10;
  inline ::google::protobuf::int32 cur_action_id() const;
  inline void set_cur_action_id(::google::protobuf::int32 value);

  // repeated .gamer.protocol.PlayerCardsMsgProtocol player_cards = 11;
  inline int player_cards_size() const;
  inline void clear_player_cards();
  static const int kPlayerCardsFieldNumber = 11;
  inline const ::gamer::protocol::PlayerCardsMsgProtocol& player_cards(int index) const;
  inline ::gamer::protocol::PlayerCardsMsgProtocol* mutable_player_cards(int index);
  inline ::gamer::protocol::PlayerCardsMsgProtocol* add_player_cards();
  inline const ::google::protobuf::RepeatedPtrField< ::gamer::protocol::PlayerCardsMsgProtocol >&
      player_cards() const;
  inline ::google::protobuf::RepeatedPtrField< ::gamer::protocol::PlayerCardsMsgProtocol >*
      mutable_player_cards();

  // @@protoc_insertion_point(class_scope:gamer.protocol.GameStartMsgProtocol)
 private:
  inline void set_has_room_id();
  inline void clear_has_room_id();
  inline void set_has_room_owner_id();
  inline void clear_has_room_owner_id();
  inline void set_has_players_num();
  inline void clear_has_players_num();
  inline void set_has_cur_round();
  inline void clear_has_cur_round();
  inline void set_has_total_round();
  inline void clear_has_total_round();
  inline void set_has_remain_cards_num();
  inline void clear_has_remain_cards_num();
  inline void set_has_banker_id();
  inline void clear_has_banker_id();
  inline void set_has_banker_is_same_time();
  inline void clear_has_banker_is_same_time();
  inline void set_has_cur_acting_player_id();
  inline void clear_has_cur_acting_player_id();
  inline void set_has_cur_action_id();
  inline void clear_has_cur_action_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 room_id_;
  ::google::protobuf::int32 room_owner_id_;
  ::google::protobuf::int32 players_num_;
  ::google::protobuf::int32 cur_round_;
  ::google::protobuf::int32 total_round_;
  ::google::protobuf::int32 remain_cards_num_;
  ::google::protobuf::int32 banker_id_;
  ::google::protobuf::int32 banker_is_same_time_;
  ::google::protobuf::int32 cur_acting_player_id_;
  ::google::protobuf::int32 cur_action_id_;
  ::google::protobuf::RepeatedPtrField< ::gamer::protocol::PlayerCardsMsgProtocol > player_cards_;
  friend void  protobuf_AddDesc_game_5fstart_5fmsg_5fprotocol_2eproto();
  friend void protobuf_AssignDesc_game_5fstart_5fmsg_5fprotocol_2eproto();
  friend void protobuf_ShutdownFile_game_5fstart_5fmsg_5fprotocol_2eproto();

  void InitAsDefaultInstance();
  static GameStartMsgProtocol* default_instance_;
};
// ===================================================================


// ===================================================================

// GameStartMsgProtocol

// required int32 room_id = 1;
inline bool GameStartMsgProtocol::has_room_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GameStartMsgProtocol::set_has_room_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GameStartMsgProtocol::clear_has_room_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GameStartMsgProtocol::clear_room_id() {
  room_id_ = 0;
  clear_has_room_id();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::room_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.room_id)
  return room_id_;
}
inline void GameStartMsgProtocol::set_room_id(::google::protobuf::int32 value) {
  set_has_room_id();
  room_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.room_id)
}

// required int32 room_owner_id = 2;
inline bool GameStartMsgProtocol::has_room_owner_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GameStartMsgProtocol::set_has_room_owner_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GameStartMsgProtocol::clear_has_room_owner_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GameStartMsgProtocol::clear_room_owner_id() {
  room_owner_id_ = 0;
  clear_has_room_owner_id();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::room_owner_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.room_owner_id)
  return room_owner_id_;
}
inline void GameStartMsgProtocol::set_room_owner_id(::google::protobuf::int32 value) {
  set_has_room_owner_id();
  room_owner_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.room_owner_id)
}

// optional int32 players_num = 3;
inline bool GameStartMsgProtocol::has_players_num() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GameStartMsgProtocol::set_has_players_num() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GameStartMsgProtocol::clear_has_players_num() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GameStartMsgProtocol::clear_players_num() {
  players_num_ = 0;
  clear_has_players_num();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::players_num() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.players_num)
  return players_num_;
}
inline void GameStartMsgProtocol::set_players_num(::google::protobuf::int32 value) {
  set_has_players_num();
  players_num_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.players_num)
}

// optional int32 cur_round = 4;
inline bool GameStartMsgProtocol::has_cur_round() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void GameStartMsgProtocol::set_has_cur_round() {
  _has_bits_[0] |= 0x00000008u;
}
inline void GameStartMsgProtocol::clear_has_cur_round() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void GameStartMsgProtocol::clear_cur_round() {
  cur_round_ = 0;
  clear_has_cur_round();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::cur_round() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.cur_round)
  return cur_round_;
}
inline void GameStartMsgProtocol::set_cur_round(::google::protobuf::int32 value) {
  set_has_cur_round();
  cur_round_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.cur_round)
}

// optional int32 total_round = 5;
inline bool GameStartMsgProtocol::has_total_round() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void GameStartMsgProtocol::set_has_total_round() {
  _has_bits_[0] |= 0x00000010u;
}
inline void GameStartMsgProtocol::clear_has_total_round() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void GameStartMsgProtocol::clear_total_round() {
  total_round_ = 0;
  clear_has_total_round();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::total_round() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.total_round)
  return total_round_;
}
inline void GameStartMsgProtocol::set_total_round(::google::protobuf::int32 value) {
  set_has_total_round();
  total_round_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.total_round)
}

// optional int32 remain_cards_num = 6;
inline bool GameStartMsgProtocol::has_remain_cards_num() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void GameStartMsgProtocol::set_has_remain_cards_num() {
  _has_bits_[0] |= 0x00000020u;
}
inline void GameStartMsgProtocol::clear_has_remain_cards_num() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void GameStartMsgProtocol::clear_remain_cards_num() {
  remain_cards_num_ = 0;
  clear_has_remain_cards_num();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::remain_cards_num() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.remain_cards_num)
  return remain_cards_num_;
}
inline void GameStartMsgProtocol::set_remain_cards_num(::google::protobuf::int32 value) {
  set_has_remain_cards_num();
  remain_cards_num_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.remain_cards_num)
}

// optional int32 banker_id = 7;
inline bool GameStartMsgProtocol::has_banker_id() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void GameStartMsgProtocol::set_has_banker_id() {
  _has_bits_[0] |= 0x00000040u;
}
inline void GameStartMsgProtocol::clear_has_banker_id() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void GameStartMsgProtocol::clear_banker_id() {
  banker_id_ = 0;
  clear_has_banker_id();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::banker_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.banker_id)
  return banker_id_;
}
inline void GameStartMsgProtocol::set_banker_id(::google::protobuf::int32 value) {
  set_has_banker_id();
  banker_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.banker_id)
}

// optional int32 banker_is_same_time = 8;
inline bool GameStartMsgProtocol::has_banker_is_same_time() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void GameStartMsgProtocol::set_has_banker_is_same_time() {
  _has_bits_[0] |= 0x00000080u;
}
inline void GameStartMsgProtocol::clear_has_banker_is_same_time() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void GameStartMsgProtocol::clear_banker_is_same_time() {
  banker_is_same_time_ = 0;
  clear_has_banker_is_same_time();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::banker_is_same_time() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.banker_is_same_time)
  return banker_is_same_time_;
}
inline void GameStartMsgProtocol::set_banker_is_same_time(::google::protobuf::int32 value) {
  set_has_banker_is_same_time();
  banker_is_same_time_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.banker_is_same_time)
}

// optional int32 cur_acting_player_id = 9;
inline bool GameStartMsgProtocol::has_cur_acting_player_id() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void GameStartMsgProtocol::set_has_cur_acting_player_id() {
  _has_bits_[0] |= 0x00000100u;
}
inline void GameStartMsgProtocol::clear_has_cur_acting_player_id() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void GameStartMsgProtocol::clear_cur_acting_player_id() {
  cur_acting_player_id_ = 0;
  clear_has_cur_acting_player_id();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::cur_acting_player_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.cur_acting_player_id)
  return cur_acting_player_id_;
}
inline void GameStartMsgProtocol::set_cur_acting_player_id(::google::protobuf::int32 value) {
  set_has_cur_acting_player_id();
  cur_acting_player_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.cur_acting_player_id)
}

// optional int32 cur_action_id = 10;
inline bool GameStartMsgProtocol::has_cur_action_id() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void GameStartMsgProtocol::set_has_cur_action_id() {
  _has_bits_[0] |= 0x00000200u;
}
inline void GameStartMsgProtocol::clear_has_cur_action_id() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void GameStartMsgProtocol::clear_cur_action_id() {
  cur_action_id_ = 0;
  clear_has_cur_action_id();
}
inline ::google::protobuf::int32 GameStartMsgProtocol::cur_action_id() const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.cur_action_id)
  return cur_action_id_;
}
inline void GameStartMsgProtocol::set_cur_action_id(::google::protobuf::int32 value) {
  set_has_cur_action_id();
  cur_action_id_ = value;
  // @@protoc_insertion_point(field_set:gamer.protocol.GameStartMsgProtocol.cur_action_id)
}

// repeated .gamer.protocol.PlayerCardsMsgProtocol player_cards = 11;
inline int GameStartMsgProtocol::player_cards_size() const {
  return player_cards_.size();
}
inline void GameStartMsgProtocol::clear_player_cards() {
  player_cards_.Clear();
}
inline const ::gamer::protocol::PlayerCardsMsgProtocol& GameStartMsgProtocol::player_cards(int index) const {
  // @@protoc_insertion_point(field_get:gamer.protocol.GameStartMsgProtocol.player_cards)
  return player_cards_.Get(index);
}
inline ::gamer::protocol::PlayerCardsMsgProtocol* GameStartMsgProtocol::mutable_player_cards(int index) {
  // @@protoc_insertion_point(field_mutable:gamer.protocol.GameStartMsgProtocol.player_cards)
  return player_cards_.Mutable(index);
}
inline ::gamer::protocol::PlayerCardsMsgProtocol* GameStartMsgProtocol::add_player_cards() {
  // @@protoc_insertion_point(field_add:gamer.protocol.GameStartMsgProtocol.player_cards)
  return player_cards_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::gamer::protocol::PlayerCardsMsgProtocol >&
GameStartMsgProtocol::player_cards() const {
  // @@protoc_insertion_point(field_list:gamer.protocol.GameStartMsgProtocol.player_cards)
  return player_cards_;
}
inline ::google::protobuf::RepeatedPtrField< ::gamer::protocol::PlayerCardsMsgProtocol >*
GameStartMsgProtocol::mutable_player_cards() {
  // @@protoc_insertion_point(field_mutable_list:gamer.protocol.GameStartMsgProtocol.player_cards)
  return &player_cards_;
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

#endif  // PROTOBUF_game_5fstart_5fmsg_5fprotocol_2eproto__INCLUDED
